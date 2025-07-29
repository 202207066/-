// 0709.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "framework.h"
#include "0709.h"

#define MAX_LOADSTRING 100

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.

// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: 여기에 코드를 입력합니다.

    // 전역 문자열을 초기화합니다.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_MY0709, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 애플리케이션 초기화를 수행합니다:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_MY0709));

    MSG msg;

    // 기본 메시지 루프입니다:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  함수: MyRegisterClass()
//
//  용도: 창 클래스를 등록합니다.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MY0709));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_MY0709);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   함수: InitInstance(HINSTANCE, int)
//
//   용도: 인스턴스 핸들을 저장하고 주 창을 만듭니다.
//
//   주석:
//
//        이 함수를 통해 인스턴스 핸들을 전역 변수에 저장하고
//        주 프로그램 창을 만든 다음 표시합니다.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  함수: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  용도: 주 창의 메시지를 처리합니다.
//
//  WM_COMMAND  - 애플리케이션 메뉴를 처리합니다.
//  WM_PAINT    - 주 창을 그립니다.
//  WM_DESTROY  - 종료 메시지를 게시하고 반환합니다.
//
//

HPEN myPen, osPen;
HBRUSH myBrush,osBrush;

HANDLE g_Handle[5];
int g_i = 0;

HWND g_hWnd;

LPARAM g_lParam;

DWORD WINAPI Pig(LPVOID lParam)
{
    int x, y, i = 0;
    x = LOWORD(lParam);
    y = HIWORD(lParam);

    HDC hdc = GetDC(g_hWnd);

    for (i = 0; i < y; i++) {
        MoveToEx(hdc, x, 0, NULL);
        LineTo(hdc, x, i);
        Sleep(20);
    }

    ReleaseDC(g_hWnd, hdc);

    return 0;
}

DWORD WINAPI Pig2(LPVOID hWnd2)
{
    int x, y, i = 0;
    x = LOWORD(g_lParam);
    y = HIWORD(g_lParam);

    HWND hWnd = (HWND)hWnd2;
    HDC hdc = GetDC(hWnd);

    for (i = 0; i < y; i++) {
        MoveToEx(hdc, x, 0, NULL);
        LineTo(hdc, x, i);
        Sleep(5);
    }

    ReleaseDC(hWnd, hdc);

    return 0;
}

void drow(LPARAM lParam, HWND hWnd)
{
    int x, y, i = 0;
    x = LOWORD(lParam);
    y = HIWORD(lParam);

    HDC hdc = GetDC(hWnd);

    for (i = 0; i < y; i++) {
        MoveToEx(hdc, x, 0, NULL);
        LineTo(hdc, x, i);
        Sleep(20);
    }

    ReleaseDC(hWnd, hdc);


}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_LBUTTONDOWN:
    {
        g_hWnd = hWnd;
        g_lParam = lParam;
       
        /// lParam 을 인수로 전달할 경우
        ///보안 속성 , 기본 스택크기 , 스레드 함수 주소 , 함수에 넘길 데이터 , 실행 여부, 저장할 스레드 id
        /*CreateThread(NULL, 0, Pig, (LPVOID)lParam, 0, NULL);
        CreateThread(NULL, 0, Pig, (LPVOID)lParam, 0, NULL);
        CreateThread(NULL, 0, Pig, (LPVOID)lParam, 0, NULL);
        CreateThread(NULL, 0, Pig, (LPVOID)lParam, 0, NULL);
        CreateThread(NULL, 0, Pig, (LPVOID)lParam, 0, NULL);*/
        
        
        /// hWnd를 인수를 받는 경우
        /*CreateThread(NULL, 0, Pig2, (LPVOID)hWnd, 0, NULL);
        CreateThread(NULL, 0, Pig2, (LPVOID)hWnd, 0, NULL);
        CreateThread(NULL, 0, Pig2, (LPVOID)hWnd, 0, NULL);
        CreateThread(NULL, 0, Pig2, (LPVOID)hWnd, 0, NULL);
        CreateThread(NULL, 0, Pig2, (LPVOID)hWnd, 0, NULL);*/

        ///drow(lParam, hWnd);

        ///스레드 핸들사용
        g_Handle[g_i++] = CreateThread(NULL, 0, Pig, (LPVOID)lParam, 0, NULL);



        break;
    }

    case WM_KEYDOWN:
    {
        int i = 0;
        /// 스레드 작업 재개
        for (i = 0; i < 5; i++) {
            ResumeThread(g_Handle[i]);

        }
        break;
    }
    case WM_RBUTTONDOWN:
    {
        int i = 0;
        ///스레드 일시중단
        for (i = 0; i < 5; i++) {
            SuspendThread(g_Handle[i]);

        }
        break;
    }
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // 메뉴 선택을 구문 분석합니다:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...
            myPen= CreatePen(PS_SOLID,5,RGB(rand()%255, rand() % 255, rand() % 255));
            myBrush = CreateSolidBrush(RGB(rand() % 255, rand() % 255, rand() % 255));
            osPen = (HPEN)SelectObject(hdc, myPen);
            osBrush = (HBRUSH)SelectObject(hdc, myBrush);
            MoveToEx(hdc, 0, 0, NULL);
            LineTo(hdc, 100, 100);

            Rectangle(hdc, 100, 100, 150, 150);

      
            SelectObject(hdc, osPen);
            SelectObject(hdc, osBrush);

            DeleteObject(myPen);
            DeleteObject(osBrush);

            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// 정보 대화 상자의 메시지 처리기입니다.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
