class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> q_students;
        stack<int> s_sandwiches;

        // Initialize queues and stacks
        for (int student : students)
            q_students.push(student);

        for (int i = sandwiches.size() - 1; i >= 0; --i)
            s_sandwiches.push(sandwiches[i]);
        
        int count=0;
        while (!q_students.empty()) {
            int student = q_students.front();
            q_students.pop();

            if (student == s_sandwiches.top()) {
                s_sandwiches.pop();
                count=0; 
            } else {
                q_students.push(student);
                count++;
            }
            if (q_students.size() == count)
                break;
        }

        return q_students.size();
    }
};
