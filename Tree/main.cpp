#include <iostream>
using namespace std;
struct strTree
{
	int index;
	int data;
	strTree * leftElem = nullptr;
	strTree * rightElem = nullptr;
	strTree * prevElem = nullptr;
};
class claTree
{
public:
	claTree()
	{
		head = nullptr;
	}
	~claTree()
	{
		deleteAllTree();
	}
	void addElem(int userIndex, int userData)
	{
		strTree * newElem = new strTree;
		newElem->data = userData;
		newElem->index = userIndex;
		if (head == nullptr)
		{
			head = newElem;
			head->leftElem = nullptr;
			head->rightElem = nullptr;
		}
		else
		{
			strTree * temp = head;
			while (temp != nullptr)
			{
				if (userIndex < temp->index)
				{
					if (temp->leftElem == nullptr) 
					{
						temp->leftElem = newElem;
						newElem->prevElem = temp;
						return;
					}
					temp = temp->leftElem;
				}
				else if (userIndex > temp->index)
				{
					if (temp->rightElem == nullptr) 
					{
						temp->rightElem = newElem;
						newElem->prevElem = temp;
						return;
					}
					temp = temp->rightElem;

				}
				else if (userIndex == temp->index)
				{
					temp->data = userData;
					delete newElem;
					return;
				}
			}
		}
	}
	void findElem(int userIndex)
	{
		strTree * finder = head;
		while (finder != nullptr)
		{
			if (userIndex < finder->index)
			{
				if (finder->leftElem == nullptr)
				{
					cout << "error 404 not found" << endl;
					break;
				}
				else 
					finder = finder->leftElem;
			}
			else if (userIndex > finder->index)
			{
				if (finder->rightElem == nullptr)
				{
					cout << "error 404 not found" << endl;
					break;
				}
				else
					finder = finder->rightElem;
			}
			else if (userIndex == finder->index)
			{
				cout << finder->index << "\t==\t" << finder->data << endl;
				break;
			}
		}
	}
	void deleteElem(int userIndex)
	{
		strTree * delRun = head;
		while (delRun != nullptr)
		{
			if (userIndex < delRun->index)
			{
				delRun = delRun->leftElem;
			}
			else if (userIndex > delRun->index)
			{
				delRun = delRun->rightElem;
			}
			else if (userIndex == delRun->index)
			{
				break;
			}
			else if (delRun == nullptr)
			{
				cout << "404 not found" << endl;
				return;
			}
		}
		if (delRun != nullptr)
		{
			if (delRun->leftElem == nullptr && delRun->rightElem == nullptr && delRun->prevElem == nullptr)
			{
				deleteAllTree();
				return;
			}
			else if (delRun->leftElem == nullptr && delRun->rightElem == nullptr)
			{
				if (delRun->prevElem->rightElem == delRun)
				{
					delRun->prevElem->rightElem = nullptr;
				}
				else if (delRun->prevElem->leftElem == delRun)
				{
					delRun->prevElem->leftElem = nullptr;
				}
			}
			else if (delRun == head)
			{
				if (delRun->rightElem != nullptr)
				{
					strTree * delRunRight = delRun->rightElem;
					delRunRight->prevElem = nullptr;
					head = head->rightElem;
					if (delRun->leftElem != nullptr)
					{
						while (delRunRight->leftElem != nullptr)
						{
							delRunRight = delRunRight->leftElem;
						}
						strTree * delRunLeft = delRun->leftElem;
						delRunLeft->prevElem = delRunRight;
						delRunRight->leftElem = delRunLeft;
					}
				}
				else if (delRun->rightElem == nullptr && delRun->leftElem != nullptr)
				{
					strTree * delRunLeft = delRun->leftElem;
					delRunLeft->prevElem = nullptr;
					head = head->leftElem;
				}
			}
			
				else if (delRun->rightElem != nullptr)
				{
					strTree * delRunRight = delRun->rightElem;
					delRunRight->prevElem = delRun->prevElem;
					if (delRunRight->index > delRun->prevElem->index)
					{
						delRun->prevElem->rightElem = delRunRight;
					}
					else if (delRunRight->index < delRun->prevElem->index)
					{
						delRun->prevElem->leftElem = delRunRight;
					}
					if (delRun->leftElem != nullptr)
					{
						while (delRunRight->leftElem != nullptr)
						{
							delRunRight = delRunRight->leftElem;
						}
						strTree * delRunLeft = delRun->leftElem;
						delRunLeft->prevElem = delRunRight;
						delRunRight->leftElem = delRunLeft;
					}
				}
				else if (delRun->rightElem == nullptr && delRun->leftElem != nullptr)
				{
					strTree * delRunLeft = delRun->leftElem;
					delRunLeft->prevElem = delRun->prevElem;
					if (delRunLeft->index > delRun->prevElem->index)
					{
						delRun->prevElem->rightElem = delRunLeft;
					}
					else if (delRunLeft->index < delRun->prevElem->index)
					{
						delRun->prevElem->leftElem = delRunLeft;
					}
				}
			delete delRun;
		}
		else
		{
			cout << "error 404 not found" << endl;
			return;
		}
	}
	void deleteAllTree()
	{
		strTree * delRun = head;
		deleteTreePrivate(delRun);
		head = nullptr;
	}
private:
	strTree * head;
	
	void deleteTreePrivate(strTree * delElem)
	{
		if (delElem != nullptr)
		{
			deleteTreePrivate(delElem->leftElem);
			deleteTreePrivate(delElem->rightElem);
			delete delElem;
		}
	}
};
int main()
{
	
	claTree kek;
	kek.addElem(42, 44);
	kek.findElem(42);
	kek.deleteElem(42);
	kek.findElem(42);
	system("pause");
	return 0;
}