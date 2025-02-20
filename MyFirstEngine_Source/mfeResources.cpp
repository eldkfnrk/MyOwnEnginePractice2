#include "mfeResources.h"

namespace mfe {
	std::map<std::wstring, Resource*> Resources::mResources = {};  //정적 변수는 반드시 초기화를 시켜주어야 한다.
}