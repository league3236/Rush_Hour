
#include <windows.h>
#include <stdio.h> // sprintf_s 관련
char Str[32]; // 그냥 문자열 선언
RECT crt; // 직사각형모양 범위 선언

// 더블버퍼링은 보통 타이머 등과 같이 연동해서 씁니다.
// 여기 예제에서는 순수하게 더블버퍼링과 관련된 것만 코딩하려고 노력하였기에
// 실행시 기존화면출력과 별로 구별되어 보이지 않는 것이 정상입니다.

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hdc, hMemDC; // HDC를 하나더 선언해준다. HDC는 '그리는 작업' 이다.
	HBITMAP hBitmap, OldBitmap; // HBITMAP은 대략 종이를 의미한다. 종이 2장 선언
	PAINTSTRUCT ps;

	switch (iMessage) {
	case WM_CREATE:
		GetClientRect(hWnd, &crt); // 시작할때 현재 창 범위를 crt 에 기억한다.
		return 0;

	case WM_PAINT: // 페인트 이벤트 → InvalidateRect(hWnd, NULL, FALSE); 로 호출
		hdc = BeginPaint(hWnd, &ps); // 그리기 시작

		hMemDC = CreateCompatibleDC(hdc); // hMemDC 에 기존 DC (hdc)에 맞게 새 DC 생성
		hBitmap = CreateCompatibleBitmap(hdc, crt.right, crt.bottom); // crt 규격대로 종이 생성
		OldBitmap = (HBITMAP)SelectObject(hMemDC, hBitmap); // 종이 교체
		// 새 DC 생성하면 그에 딸린 펜, 붓, 종이 같은 것들도 기본값으로 다 셋팅되는데,
		// 셋팅된 종이가 가로세로 0 x 0 인 종이라 crt 규격인 종이로 글씨체 설정하듯 교체해주어야 하는 것 같음.
		// 아니면 말고. 그냥 추측이니까.... 틀린 것일 수도 있음. 난 컴공대생이 아니라 아마추어일 뿐이라고.

		// 이부분에 그린다. 주의할 점은 hdc 대신 hMemDC 로 설정해서 그려야 한다는 것.
		sprintf_s(Str, "더블 버퍼링"); TextOutA(hMemDC, 10, 10, Str, lstrlenA(Str));
		sprintf_s(Str, "화면 전환시 깜빡임 방지"); TextOutA(hMemDC, 10, 30, Str, lstrlenA(Str));

		BitBlt(hdc, 0, 0, crt.right, crt.bottom, hMemDC, 0, 0, SRCCOPY); // 배껴그리기
		// hdc 의 0,0 위치에 hMemDC의 0,0위치부터 crt.right,crt.bottom까지의 영역, 즉 crt범위를 그린다 라는 설정인듯.

		DeleteObject(SelectObject(hMemDC, OldBitmap)); // 종이 원래대로 한 후 제거
		DeleteDC(hMemDC); // hMemDC 제거

		EndPaint(hWnd, &ps); // 그리기 종료
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hWnd, iMessage, wParam, lParam);
}

int main()
{
	WndProc()
}