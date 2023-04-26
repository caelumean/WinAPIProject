#include "CollisionManager.h"
#include "Scene.h"
#include "SceneManager.h"

//CollisionManaget �ʱ�ȭ
WORD CollisionManager::mMatrix[(UINT)eLayerType::End] = {};
std::map<UINT64, bool> CollisionManager::mCollisionMap;

void CollisionManager::Update()
{
	// ���� �� ��������
	Scene* scene = SceneManager::GetActiveScene();

	// �� �κ� �м��� �ؾ��� �� 
	// Matrix(���)�� ����
	for (UINT row = 0; row < (UINT)eLayerType::End; row++)
	{
		for (UINT col = 0; col < (UINT)eLayerType::End; col++)
		{
			// col�� 3�̸� 1�� �������� 3ĭ �ű�ڴٴ� ��
			// ����Ʈ������
			if (mMatrix[row] & (1 << col))
			{
				// ���� �� �ѱ�� 
				LayerCollision(scene, (eLayerType)row, (eLayerType)col);
			}
		}
	}
}

void CollisionManager::LayerCollision(Scene* scene, eLayerType left, eLayerType right)
{
	// PlayerLayer�� �ִ°� �� ������
	const std::vector<GameObject*>& lefts = scene->GetGameObjects(left);
	// ���Ϳ� �ִ°� �� ������
	const std::vector<GameObject*>& rights = scene->GetGameObjects(right);

	// �� ��
	for (auto leftObject : lefts)
	{
		// Player�� Collider�� ���� ���
		Collider* leftCollider = leftObject->GetComponent<Collider>();
		if (leftCollider == nullptr)
			continue;

		for (auto rightObject : rights)
		{
			// ���͵� ���� ���
			Collider* rightCollider = rightObject->GetComponent<Collider>();
			if (rightCollider == nullptr)
				continue;

			if (leftObject == rightObject)
				continue;

			ColliderCollision(leftCollider, rightCollider, left, right);
		}
	}
}

void CollisionManager::ColliderCollision(Collider* leftCol, Collider* rightCol, eLayerType left, eLayerType right)
{
	ColliderID colliderID = {};
	colliderID.left = (UINT)leftCol->GetID();
	colliderID.right = (UINT)rightCol->GetID();

	//static std::map<UINT64, bool> mCollisionMap;
	std::map<UINT64, bool>::iterator iter
		= mCollisionMap.find(colliderID.id);

	// end��� �ѹ��� �浹�� ���� ���� ��
	if (iter == mCollisionMap.end())
	{
		mCollisionMap.insert(std::make_pair(colliderID.id, false));
		iter = mCollisionMap.find(colliderID.id);
	}

	if (Intersect(leftCol, rightCol))
	{
		// �������� �浹�� ������ ���� ��� �浹�ߴ�.
		// ���� �浹 ���������� enter
		if (iter->second == false)
		{
			leftCol->OnCollisionEnter(rightCol);
			rightCol->OnCollisionEnter(leftCol);

			iter->second = true;
		}
		// ��� Collider�ȿ� �ӹ��� ���� ��
		// �浹 ���λ��� stay 
		else
		{
			leftCol->OnCollisionStay(rightCol);
			rightCol->OnCollisionStay(leftCol);
		}
	}
	else
	{
		// Exit
		// ���������� �浹 O
		// ����� �浹 X 
		if (iter->second == true)
		{
			leftCol->OnCollisionExit(rightCol);
			rightCol->OnCollisionExit(leftCol);

			//true���� �� �浹�� �������ϱ� false�� �ٲ�����Ѵ�.
			iter->second = false;
		}
	}
}

bool CollisionManager::Intersect(Collider* left, Collider* right)
{
	Vector2 leftPos = left->GetPos();
	Vector2 rightPos = right->GetPos();

	// �� �浹ü ���� �Ÿ���, �������� ���ݳ����� ���� ���ؼ�
	// �Ÿ��� �� ��ٸ� �浹 X, �Ÿ��� �� ª�ٸ� �浹 O
	Vector2 leftSize = left->GetSize();
	Vector2 rightSize = right->GetSize();

	leftPos.x = leftPos.x + leftSize.x / 2.0f;
	leftPos.y = leftPos.y + leftSize.y / 2.0f;

	rightPos.x = rightPos.x + rightSize.x / 2.0f;
	rightPos.y = rightPos.y + rightSize.y / 2.0f;


	// �Ÿ��� ������ �ʿ���� ������
	// fabs : ���밪�� �����ִ� �Լ�
	if (fabs(leftPos.x - rightPos.x) < (leftSize.x / 2.0f) + (rightSize.x / 2.0f)
		&& fabs(leftPos.y - rightPos.y) < (leftSize.y / 2.0f) + (rightSize.y / 2.0f))
	{
		return true;
	}

	return false;
}

void CollisionManager::SetLayer(eLayerType left, eLayerType right, bool value)
{
	UINT row = 0;
	UINT col = 0;

	UINT ileft = (UINT)left;
	UINT iright = (UINT)right;

	if (left <= right)
	{
		row = ileft;
		col = iright;
	}
	else
	{
		row = iright;
		col = ileft;
	}

	if (value == true)
		mMatrix[row] |= (1 << col);
	else
		// ~ : 0�̸� 1 , 1�̸� 0
		mMatrix[row] &= ~(1 << col);
}

void CollisionManager::Clear()
{
	// ���� �ٲ�� �浹 ������ �޶����� ������
	// ���� �ٲ� ���Ӱ� �ʱ�ȭ
	memset(mMatrix, 0, sizeof(WORD) * (UINT)eLayerType::End);
	mCollisionMap.clear();
}
