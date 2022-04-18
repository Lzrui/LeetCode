//
// Created by l50021384 on 2022/4/6.
//
#include <string>
using namespace std;
//深度优先搜索
class Solution {
public:
    int index = 0;

    NestedInteger deserialize(string s) {
        if (s[index] == '[') {
            index++;
            NestedInteger ni;
            while (s[index] != ']') {
                ni.add(deserialize(s));
                if (s[index] == ',') {
                    index++;
                }
            }
            index++;
            return ni;
        } else {
            bool negative = false;
            if (s[index] == '-') {
                negative = true;
                index++;
            }
            int num = 0;
            while (index < s.size() && isdigit(s[index])) {
                num = num * 10 + s[index] - '0';
                index++;
            }
            if (negative) {
                num *= -1;
            }
            return NestedInteger(num);
        }
    }
};
//栈
//class Solution {
//public:
//    NestedInteger deserialize(string s) {
//        if (s[0] != '[') {
//            return NestedInteger(stoi(s));
//        }
//        stack<NestedInteger> st;
//        int num = 0;
//        bool negative = false;
//        for (int i = 0; i < s.size(); i++) {
//            char c = s[i];
//            if (c == '-') {
//                negative = true;
//            } else if (isdigit(c)) {
//                num = num * 10 + c - '0';
//            } else if (c == '[') {
//                st.emplace(NestedInteger());
//            } else if (c == ',' || c == ']') {
//                if (isdigit(s[i - 1])) {
//                    if (negative) {
//                        num *= -1;
//                    }
//                    st.top().add(NestedInteger(num));
//                }
//                num = 0;
//                negative = false;
//                if (c == ']' && st.size() > 1) {
//                    NestedInteger ni = st.top();
//                    st.pop();
//                    st.top().add(ni);
//                }
//            }
//        }
//        return st.top();
//    }
//};
