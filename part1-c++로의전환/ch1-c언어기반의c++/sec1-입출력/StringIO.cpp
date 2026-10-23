#include <iostream>

int main(void)
{
	char name[100];
	char lang[200];

	std::cout<<"이름은 무엇입니까?";
	std::cin>>name;

	std::cout<<"좋아하는 프로그래밍 언어는?";
	std::cin>>lang;

	std::cout<<"이름은 "<<name<<"입니다.\n";
	std::cout<<"제일 좋아하는 언어는 "<<lang<<"입니다."<<std::endl;
	return 0;
}

/*
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabbbbb
배열 범위 초과하는 입력 테스트
```
❯ ./a.out
이름은 무엇입니까?aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabbbbb
좋아하는 프로그래밍 언어는?kk
이름은 aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabbbbb입니다.
제일 좋아하는 언어는 kk입니다.
❯ ./a.out
이름은 무엇입니까?aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabbbbbaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabbbbb
좋아하는 프로그래밍 언어는?kk
이름은 aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabbbbbaaaaaaakk입니다.
제일 좋아하는 언어는 kk입니다.
```






`char` 배열 버퍼 크기(100바이트)보다 훨씬 긴 문자열을 `std::cin >> name;`으로 입력했을 때 발생하는 전형적인 **메모리 침범(Buffer Overflow / Undefined Behavior)** 현상입니다.

### 1. 첫 번째 테스트: 버퍼 크기는 넘었지만 동작한 이유

입력한 문자열 길이(100자 이상)가 `name[100]`의 크기를 넘어섰습니다.

* `std::cin >> name;`은 입력받는 배열의 크기를 모르기 때문에, 입력된 모든 글자를 메모리에 계속 덮어씁니다.
* 이때 `name` 뒤쪽 메모리 공간(스택 영역)을 넘어가서 다른 데이터를 덮어썼지만, 다행히 프로그램 실행을 즉시 멈추게 하는 치명적인 메모리 영역(예: 리턴 주소 등)까지는 깨뜨리지 않고 지나간 것입니다.
* C/C++에서는 이를 정의되지 않은 동작(Undefined Behavior)이라고 부릅니다. 운 좋게 종료되지 않고 출력까지 정상처럼 보였을 뿐, 이미 메모리는 오염된 상태입니다.

---

### 2. 두 번째 테스트: 문자열이 섞여서 출력된 이유 (`aaaaaakk` 형태)

두 번째 테스트에서는 훨씬 더 길게 입력하면서 메모리 오염이 심해져, **`name` 배열과 `lang` 배열의 메모리 위치가 서로 겹치는 현상**이 발생했습니다.

1. **메모리 배치:** 스택 메모리상에서 `name[100]`과 `lang[200]`은 서로 인접하게 배치되어 있습니다.
2. **`name` 입력 시점:** 엄청나게 긴 `a...b` 문자열이 들어가면서 `name` 영역을 넘어 바로 옆에 있던 `lang` 배열 영역까지 전부 `a...b`로 덮어써 버렸습니다.
3. **`lang` 입력 시점 (`kk` 입력):**
* 그 후 `std::cin >> lang;`을 통해 `kk`를 입력받았습니다.
* `lang` 배열의 시작점에 `k`, `k`, `\0`(널 문자)이 저장되면서, 방금 `name`이 넘쳐서 적어두었던 메모리의 앞부분을 `kk\0`으로 다시 덮어썼습니다.


4. **`cout << name` 출력 시점:**
* C/C++에서 문자열 출력은 **`\0`(널 문자)을 만날 때까지** 진행됩니다.
* `name`을 출력하다가, 옆의 `lang` 메모리 영역으로 넘어가서 `lang`에 방금 들어간 `kk` 뒤의 `\0`을 만나 비로소 출력을 멈추게 된 것입니다.
* 그 결과 `name` 출력 시 `a...a` 끝에 `kk`가 붙어 나오는 기괴한 출력이 만들어졌습니다.



---

### 3. 해결 방법: C++ 다운 방식 적용하기

#### ① `std::string` 사용 (가장 추천하는 C++ manner)

`char` 배열 대신 동적 메모리를 관리하는 `std::string`을 사용하면 버퍼 오버플로우 걱정이 완전히 사라집니다.

```cpp
#include <iostream>
#include <string>

int main(void)
{
    std::string name;
    std::string lang;

    std::cout << "이름은 무엇입니까?";
    std::cin >> name; // 길이에 맞게 자동으로 메모리가 확장됨

    std::cout << "좋아하는 프로그래밍 언어는?";
    std::cin >> lang;

    std::cout << "이름은 " << name << "입니다.\n";
    std::cout << "제일 좋아하는 언어는 " << lang << "입니다." << std::endl;
    return 0;
}

```

#### ② `char` 배열을 유지해야 한다면: `std::setw` 사용

`<iomanip>`의 `std::setw`를 사용하면 입력받을 최대 자릿수를 제한하여 버퍼 오버플로우를 막을 수 있습니다.

```cpp
#include <iostream>
#include <iomanip>

int main(void)
{
    char name[100];
    
    std::cout << "이름은 무엇입니까?";
    // 널 문자(\0) 공간 1바이트를 제외하고 최대 99자만 읽음
    std::cin >> std::setw(sizeof(name)) >> name;
    
    return 0;
}

```

`ex01` 과제처럼 사용자의 예외 입력을 안전하게 처리하려면 `char` 배열 고정 크기보다는 **`std::string`과 `std::getline` 조합**을 사용하는 것이 훨씬 안전합니다.
*/