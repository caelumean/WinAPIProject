#pragma once
#include "Entity.h"

// ���������Լ��� �ϳ��� �����ϰ� �ִٸ� 
// �߻�Ŭ������ �ȴ�.
// �׷��� �޸��Ҵ� ��ü�� �ȵȴ�.
// ������ ��Ӹ� �޾Ƽ� ����϶�.
class Resource
{
public:
	Resource();
	//virtual �̶�� ���������Լ��� �ϳ��� �����ϰ� �ֱ⶧����
	// �߻�Ŭ������ �ȴ�.
	virtual ~Resource();

	//���� ���
	// = 0(���������Լ�) �� ���̸� �긦 ��ӹ޴� ��� �ֵ���� �ʼ������� ��������� �Ѵ�.
	virtual HRESULT Load(const std::wstring& path) = 0;

	// wstring�� &(����)�� �Ⱥ��̸� ���� ����Ǳ⶧����
	// ���� ��� ���ڿ��� 120���ڸ� ���ο��� for���� ��� ������ �ѱ�� ������
	// ������ �ٿ��� �ּҷ� �Ѱܾ� �Ѵ�.
	const std::wstring& GetKey() { return mKey; }
	const std::wstring& GetPath() { return mPath; }
	void SetKey(const std::wstring& key) { mKey = key; }
	void SetPath(const std::wstring& path) { mPath = path; }

private:
	// wstring�� ���ڿ� �ڷ����̴�
	std::wstring mKey;
	std::wstring mPath;

};

