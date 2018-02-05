#include <Windows.h>
#include <iostream>

class DoubleBuffer
{
public:
	DoubleBuffer();
	~DoubleBuffer();

	void createBuffer(const int& width, const int& height); // ���� ����
	void writeBuffer(int x, int y, char *string);           // ���� ����
	void flippingBuffer();                                  // ���� ��ȯ
	void clearBuffer();                                     // ���� �����
	void destroyBuffer();                                   // ���� ����

private:
	int m_nBufferIndex;                                     // ���� Index

	HANDLE m_hBuffer[2];
	// HANDLE
	// �ڵ��� ��ü���� � ����� �����ϱ� ���� �ٿ��� ������ ��ȣ. 
	// � ü���� �ο��ϴ� �ߺ����� �ʴ� ������.
	// �������� object�� structure ���� �����͸� ���� �ٷ����� ������ ���� ó��
	// ���輺 ������ ��ü�� ��Ī�ϴµ� �����͸� ���� �ʰ� ��ȣ�� �� ���̴�.

	bool MyCloseHandle(HANDLE& hFile);         // �����ϰ� CloseHandle ó�� 
};