#pragma once
//이 헤더 파일은 자주 사용할 헤더 파일들을 하나의 파일에 모아서 편하게 사용하기 위해 만들어진 파일

#include <Windows.h>  //WinApi 헤더 파일
#include <vector>
#include <algorithm>  //for_each를 사용하기 위한 헤더 파일
#include <string>
#include <map>  //map은 트리 자료 구조를 사용하기 위한 헤더 파일

#include "mfeMath.h"

#include <mmsystem.h>
#include <dinput.h>
#pragma comment(lib, "Msimg32.lib")
#pragma comment(lib, "winmm.lib")

#include <gdiplus.h>
#pragma comment(lib, "gdiplus.lib")

#include "mfeEnums.h"