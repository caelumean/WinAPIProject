#include "CollisionManager.h"
#include "Scene.h"
#include "SceneManager.h"

//CollisionManaget 초기화
WORD CollisionManager::mMatrix[(UINT)eLayerType::End] = {};
std::map<UINT64, bool> CollisionManager::mCollisionMap;

void CollisionManager::Update()
{
	// 현재 씬 가져오기
	Scene* scene = SceneManager::GetActiveScene();

	// 이 부분 분석좀 해야할 듯 
	// Matrix(행렬)을 만듦
	for (UINT row = 0; row < (UINT)eLayerType::End; row++)
	{
		for (UINT col = 0; col < (UINT)eLayerType::End; col++)
		{
			// col이 3이면 1을 왼쪽으로 3칸 옮기겠다는 뜻
			// 쉬프트연산자
			if (mMatrix[row] & (1 << col))
			{
				// 현재 씬 넘기고 
				LayerCollision(scene, (eLayerType)row, (eLayerType)col);
			}
		}
	}
}

void CollisionManager::LayerCollision(Scene* scene, eLayerType left, eLayerType right)
{
	// PlayerLayer에 있는거 다 가져옴
	const std::vector<GameObject*>& lefts = scene->GetGameObjects(left);
	// 몬스터에 있는거 다 가져옴
	const std::vector<GameObject*>& rights = scene->GetGameObjects(right);

	// 다 비교
	for (auto leftObject : lefts)
	{
		// Player가 Collider가 없는 경우
		Collider* leftCollider = leftObject->GetComponent<Collider>();
		if (leftCollider == nullptr)
			continue;

		for (auto rightObject : rights)
		{
			// 몬스터도 없는 경우
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

	// end라면 한번도 충돌한 적이 없는 거
	if (iter == mCollisionMap.end())
	{
		mCollisionMap.insert(std::make_pair(colliderID.id, false));
		iter = mCollisionMap.find(colliderID.id);
	}

	if (Intersect(leftCol, rightCol))
	{
		// 이전에는 충돌을 한적이 없고 방금 충돌했다.
		// 최초 충돌 시작했을때 enter
		if (iter->second == false)
		{
			leftCol->OnCollisionEnter(rightCol);
			rightCol->OnCollisionEnter(leftCol);

			iter->second = true;
		}
		// 계속 Collider안에 머물고 있을 때
		// 충돌 중인상태 stay 
		else
		{
			leftCol->OnCollisionStay(rightCol);
			rightCol->OnCollisionStay(leftCol);
		}
	}
	else
	{
		// Exit
		// 이전프레임 충돌 O
		// 현재는 충돌 X 
		if (iter->second == true)
		{
			leftCol->OnCollisionExit(rightCol);
			rightCol->OnCollisionExit(leftCol);

			//true였는 데 충돌이 끝났으니까 false로 바꿔줘야한다.
			iter->second = false;
		}
	}
}

bool CollisionManager::Intersect(Collider* left, Collider* right)
{
	Vector2 leftPos = left->GetPos();
	Vector2 rightPos = right->GetPos();

	// 두 충돌체 간의 거리와, 각면적의 절반끼리의 합을 비교해서
	// 거리가 더 길다면 충돌 X, 거리가 더 짧다면 충돌 O
	Vector2 leftSize = left->GetSize();
	Vector2 rightSize = right->GetSize();

	leftPos.x = leftPos.x + leftSize.x / 2.0f;
	leftPos.y = leftPos.y + leftSize.y / 2.0f;

	rightPos.x = rightPos.x + rightSize.x / 2.0f;
	rightPos.y = rightPos.y + rightSize.y / 2.0f;


	// 거리는 음수가 필요없기 때문에
	// fabs : 절대값을 구해주는 함수
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
		// ~ : 0이면 1 , 1이면 0
		mMatrix[row] &= ~(1 << col);
}

void CollisionManager::Clear()
{
	// 씬이 바뀌면 충돌 정보가 달라지기 때문에
	// 씬이 바뀔때 새롭게 초기화
	memset(mMatrix, 0, sizeof(WORD) * (UINT)eLayerType::End);
	mCollisionMap.clear();
}
