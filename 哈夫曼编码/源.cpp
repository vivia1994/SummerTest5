#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

template <class ElemType>
struct Node
{
	ElemType d;
	int io;
	Node<ElemType> *lC;
	Node<ElemType> *rC;
	string hC;
	Node(ElemType newDate, int newInputOrder)
	{
		lC = rC = NULL;
		d = newDate;
		io = newInputOrder;
	}
};

void CHC(Node<int>  *root)
{
	
	if (root->lC != NULL)
	{
		
		root->lC->hC = root->hC + "0"; 
		CHC(root->lC); 
	}
	if (root->rC != NULL)
	{
		
		root->rC->hC = root->hC + "1"; 
		CHC(root->rC); 
	}
}

void SHC(Node<int> *root)
{
	
	CHC(root); 
	struct
	{
		int d;
		string hc; 
	} ohc[1000];
	queue<Node<int> *> nq; 
	nq.push(root); 
	while (!nq.empty())
	{
		
		Node<int> * node = nq.front();
		nq.pop(); 
		bool f = true; 
		if (node->lC != NULL)
		{
			
			f = false; 
			nq.push(node->lC);
		}
		if (node->rC != NULL)
		{
			f = false; 
			nq.push(node->rC);
		}
		if (f)
		{
			
			ohc[node->io].d = node->d; 
			ohc[node->io].hc = node->hC;
		}
	}
	for (int i = 1; i < 1000; ++i)
	{
		
		if (ohc[i].hc.length() == 0)
			break; 
		cout << ohc[i].d << " " << ohc[i].hc << endl; 
	}
}

int main(void)
{
	
	int cn; 
	cin >> cn; 
	int cc = 0; 
	while (++cc <= cn)
	{
		
		Node<int>* trees[1000]; 
		int tc = 0; 
		int vn; 
		int vc = 0; 
		cin >> vn; 
		while (++vc <= vn)
		{
			
			int v; 
			cin >> v; 
			trees[tc++] = new Node<int>(v, vc); 
		}
		//-----------------------------------------------------------
		while (tc > 1)
		{
			
			int mi = -1; 
			for (int i = tc - 1; i >= 0; --i)
			{
				
				if (mi == -1 || trees[i]->d < trees[mi]->d)
					mi = i; 
			}
			if (mi != tc - 1)
			{
				
				Node<int>* tmp = trees[mi];
				for (int i = mi; i < tc - 1; ++i)
					trees[i] = trees[i + 1]; 
				trees[tc - 1] = tmp; 
			}
			
			int msi = -1; 
			for (int i = tc - 1 - 1; i >= 0; --i)
			{
				
				if (msi == -1 || trees[i]->d < trees[msi]->d)
					msi = i; 
			}
			if (msi != tc - 1 - 1)
			{
				
				Node<int>* tmp = trees[msi]; 
				for (int i = msi; i < tc - 1 - 1; ++i)
					trees[i] = trees[i + 1]; 
				trees[tc - 1 - 1] = tmp; 
			}
			Node<int> *nn = new Node<int>(trees[tc - 1 - 1]->d + trees[tc - 1]->d, -1);
			nn->lC = trees[tc - 1 - 1]; 
			nn->rC = trees[tc - 1]; 
			tc -= 2; 
			
			int last; 
			for (last = tc - 1; last >= 0; --last)
			{
				
				
				if (trees[last]->d >= nn->d)
					break; 
			}
			
			for (int i = tc - 1; i > last; --i)
			{
				trees[i + 1] = trees[i]; 
			}
			
			trees[last + 1] = nn; 
			++tc; 
			
		}
		//-----------------------------------------------------------
		cout << "Case " << cc << endl; 
		SHC(trees[0]); 
		cout << endl; 
	}
	
	return 0;
}