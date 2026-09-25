import java.util.*;

class Solution {
    public List<String> braceExpansionII(String expression) {
        Stack<Set<String>> stack = new Stack<>();
        Stack<Character> ops = new Stack<>();

        int i = 0;
        int n = expression.length();

        while (i < n) {
            char c = expression.charAt(i);

            if (c == '{') {
                if (i > 0 && (Character.isLetter(expression.charAt(i - 1)) || expression.charAt(i - 1) == '}')) {
                    while (!ops.isEmpty() && ops.peek() == '*') {
                        evaluateTop(stack, ops);
                    }
                    ops.push('*');
                }
                ops.push('{');
                i++;
            } else if (c == '}') {
                while (!ops.isEmpty() && ops.peek() != '{') {
                    evaluateTop(stack, ops);
                }
                ops.pop();
                i++;
            } else if (c == ',') {
                while (!ops.isEmpty() && ops.peek() != '{') {
                    evaluateTop(stack, ops);
                }
                ops.push(',');
                i++;
            } else if (Character.isLetter(c)) {
                if (i > 0 && (Character.isLetter(expression.charAt(i - 1)) || expression.charAt(i - 1) == '}')) {
                    while (!ops.isEmpty() && ops.peek() == '*') {
                        evaluateTop(stack, ops);
                    }
                    ops.push('*');
                }
                
                Set<String> set = new HashSet<>();
                set.add(String.valueOf(c));
                stack.push(set);
                i++;
            }
        }

        while (!ops.isEmpty()) {
            evaluateTop(stack, ops);
        }

        List<String> result = new ArrayList<>(stack.pop());
        Collections.sort(result);
        return result;
    }

    private void evaluateTop(Stack<Set<String>> stack, Stack<Character> ops) {
        char op = ops.pop();
        Set<String> set2 = stack.pop();
        Set<String> set1 = stack.pop();

        Set<String> res = new HashSet<>();
        if (op == '*') {
            for (String s1 : set1) {
                for (String s2 : set2) {
                    res.add(s1 + s2);
                }
            }
        } else if (op == ',') {
            res.addAll(set1);
            res.addAll(set2);
        }

        stack.push(res);
    }
}
