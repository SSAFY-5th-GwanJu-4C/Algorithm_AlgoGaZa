class Solution {
    public String solution(String new_id) {
        // 1~4 단계 
        new_id = new_id.toLowerCase()
                .replaceAll("[^a-z0-9._-]", "")
                .replaceAll("[.]{2,}", ".")
                .replaceAll("^[.]|[.]$", "");

        // 5단계
        if (new_id.isEmpty()) {
            new_id = "a";
        }

        // 6단계
        if (new_id.length() >= 16) {
            new_id = new_id.substring(0, 15);
            new_id = new_id.replaceAll("[.]$", "");
        }

        // 7단계
        if (new_id.length() <= 2) {
            while (new_id.length() < 3) {
                new_id += new_id.charAt(new_id.length() - 1);
            }
        }


        String answer = new_id;
        return answer;
    }
}
