pair<int,int> average(Node* root, double maxVal)
{

	if((root->child).size()==0)return pair<int,int>(0,1);
	int sum = root -> val;
	int count = 1 + root->child.size();
	for(int i=0;i<root->child.size();i++)
	{
		sum+=root->child[i]->val;
	}
	maxVal = max(maxVal,1.0*sum/(1.0*count));
	return pair<int,int>(sum,count);
}