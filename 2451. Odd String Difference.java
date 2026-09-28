import java.util.*;

class Solution {
    public String oddString(String[] words) {
        Map<String, List<String>> map = new HashMap<>();
        for (String word : words) {
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < word.length() - 1; i++) {
                sb.append(word.charAt(i + 1) - word.charAt(i)).append(",");
            }
            String key = sb.toString();
            map.putIfAbsent(key, new ArrayList<>());
            map.get(key).add(word);
        }
        for (List<String> list : map.values()) {
            if (list.size() == 1) {
                return list.get(0);
            }
        }
        return "";
    }
}
