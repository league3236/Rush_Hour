
#include <windows.h>
#include <stdio.h> // sprintf_s ����
char Str[32]; // �׳� ���ڿ� ����
RECT crt; // ���簢����� ���� ����

// ������۸��� ���� Ÿ�̸� ��� ���� �����ؼ� ���ϴ�.
// ���� ���������� �����ϰ� ������۸��� ���õ� �͸� �ڵ��Ϸ��� ����Ͽ��⿡
// ����� ����ȭ����°� ���� �����Ǿ� ������ �ʴ� ���� �����Դϴ�.

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hdc, hMemDC; // HDC�� �ϳ��� �������ش�. HDC�� '�׸��� �۾�' �̴�.
	HBITMAP hBitmap, OldBitmap; // HBITMAP�� �뷫 ���̸� �ǹ��Ѵ�. ���� 2�� ����
	PAINTSTRUCT ps;

	switch (iMessage) {
	case WM_CREATE:
		GetClientRect(hWnd, &crt); // �����Ҷ� ���� â ������ crt �� ����Ѵ�.
		return 0;

	case WM_PAINT: // ����Ʈ �̺�Ʈ �� InvalidateRect(hWnd, NULL, FALSE); �� ȣ��
		hdc = BeginPaint(hWnd, &ps); // �׸��� ����

		hMemDC = CreateCompatibleDC(hdc); // hMemDC �� ���� DC (hdc)�� �°� �� DC ����
		hBitmap = CreateCompatibleBitmap(hdc, crt.right, crt.bottom); // crt �԰ݴ�� ���� ����
		OldBitmap = (HBITMAP)SelectObject(hMemDC, hBitmap); // ���� ��ü
		// �� DC �����ϸ� �׿� ���� ��, ��, ���� ���� �͵鵵 �⺻������ �� ���õǴµ�,
		// ���õ� ���̰� ���μ��� 0 x 0 �� ���̶� crt �԰��� ���̷� �۾�ü �����ϵ� ��ü���־�� �ϴ� �� ����.
		// �ƴϸ� ����. �׳� �����̴ϱ�.... Ʋ�� ���� ���� ����. �� �İ������ �ƴ϶� �Ƹ��߾��� ���̶��.

		// �̺κп� �׸���. ������ ���� hdc ��� hMemDC �� �����ؼ� �׷��� �Ѵٴ� ��.
		sprintf_s(Str, "���� ���۸�"); TextOutA(hMemDC, 10, 10, Str, lstrlenA(Str));
		sprintf_s(Str, "ȭ�� ��ȯ�� ������ ����"); TextOutA(hMemDC, 10, 30, Str, lstrlenA(Str));

		BitBlt(hdc, 0, 0, crt.right, crt.bottom, hMemDC, 0, 0, SRCCOPY); // �貸�׸���
		// hdc �� 0,0 ��ġ�� hMemDC�� 0,0��ġ���� crt.right,crt.bottom������ ����, �� crt������ �׸��� ��� �����ε�.

		DeleteObject(SelectObject(hMemDC, OldBitmap)); // ���� ������� �� �� ����
		DeleteDC(hMemDC); // hMemDC ����

		EndPaint(hWnd, &ps); // �׸��� ����
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