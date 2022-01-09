Problem-540 · Zigzag Iterator
Given two 1d vectors, implement an iterator to return their elements alternately.
Example1
Input: v1 = [1, 2] and v2 = [3, 4, 5, 6]
Output: [1, 3, 2, 4, 5, 6]
Explanation: 
By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1, 3, 2, 4, 5, 6].
Example2
Input: v1 = [1, 1, 1, 1] and v2 = [3, 4, 5, 6]
Output: [1, 3, 1, 4, 1, 5, 1, 6]
class ZigzagIterator
{
public:
    queue<int> q;
    int i = 0;
    ZigzagIterator(vector<int> &v1, vector<int> &v2)
    {

        while (i < v1.size() == true || i < v2.size() == true)
        {
            if (i < v1.size())

            {
                q.push(v1[i]);
            }
            if (i < v2.size())

            {
                q.push(v2[i]);
            }
            i++;
        }
    }
    int next()
    {
        int res = q.front();
        q.pop();
        return res;
    }
    bool hasNext()
    {
        if (q.empty() == true)
        {
            return false;
        }
        return true;
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator solution(v1, v2);
 * while (solution.hasNext()) result.push_back(solution.next());
 * Ouptut result
 */