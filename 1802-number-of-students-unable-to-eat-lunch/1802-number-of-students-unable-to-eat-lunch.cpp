class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        vector<int> wants={0,0};
        int size=students.size();
        for(int i=0;i<size;i++){
            if(students[i]==0){
                wants[0]+=1;
            }else{
                wants[1]+=1;
            }
        }
        for(int i=0;i<size;i++){
            if(sandwiches[i]==0 && wants[0]>0){
                wants[0]-=1;
            }else if(sandwiches[i]==1 && wants[1]>0){
                wants[1]-=1;
            }else{
                return wants[0]+wants[1];
            }
        }
        return 0;
    }
};