#pragma once

#define DllExport   __declspec( dllexport )
#define DllImport   __declspec( dllimport )

/*
* ����� ��������� ���������� ����, � ������ � ������� ��������� �������� stateEngine, 
* �������������� ������� ����� �����������: ������� ����, � ���������, ����� ������, ���� � �.�. 
* ������� �������� �������� stateEngine ������ ��������������� ������������ ���������, 
* ��������: stateEngine = 1 - ������� ����, stateEngine = 2 - � ��������� � �.�. 
* �������� 0 � �������� sta-teEngine �������� �����.
*
* ������ ���� ������ � ��������� ������������ �������� ��:
*
*	while (engine.getState()) {
*		// ���� - 1
*		if (engine.getState() == 1) {
*			������������� ����������, ��������...
			    while (engine.getState()) {
					�������� ���� ��������� ����
				}
*		}
*		// ���� - 2
*		else if (engine.getState() == 2) {
*			������������� ����������, ��������...
			    while (engine.getState()) {
					�������� ���� ��������� ����
				}
*		}
*		......
*/

class DllExport Engine {
private:
	int stateEngine = 1; //��������� ���� (0 - ������� ����)
public:
	int getState();
	void setState(int state);
};