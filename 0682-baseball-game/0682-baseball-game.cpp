class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> record;
        int n=operations.size();
        int sum = 0;
        for(int i=0;i<n;i++){
            if(operations[i]=="+"){
                sum=record.top();
                record.pop();
                sum+=record.top();
                record.push(sum-record.top());
                record.push(sum);
            }else if(operations[i]=="D"){
                sum=record.top();
                record.push((sum*2));
            }else if(operations[i]=="C"){
                record.pop();
            }else{
                record.push(stoi(operations[i]));
            }
        }
        sum=0;
        while (!record.empty()) {
            sum += record.top();
            record.pop();
        }
        return sum;
    }
};