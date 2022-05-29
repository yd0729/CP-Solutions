class Solution {
  public:
    string validIPAddress(string queryIP) {
        int n = queryIP.size();
        if (queryIP.find('.') != string::npos) { // IPv4
            int begin = 0;
            for (int i = 0; i < 4; ++i) {
                int end = (i == 3 ? n : queryIP.find('.', begin));
                if (end == string::npos) {
                    return "Neither";
                }
                if (end - begin < 1 || end - begin > 3) {
                    return "Neither";
                }

                int addr = 0;
                for (int j = begin; j < end; ++j) {
                    if (!isdigit(queryIP[j])) {
                        return "Neither";
                    }
                    addr = addr * 10 + (queryIP[j] - '0');
                }

                if (addr > 255) {
                    return "Neither";
                }
                if (addr > 0 && queryIP[begin] == '0') { // 有前导零
                    return "Neither";
                }
                if (addr == 0 && end - begin > 1) { // 有前导零
                    return "Neither";
                }
                begin = end + 1;
            }
            return "IPv4";
        } else { // IPv6
            int begin = 0;
            for (int i = 0; i < 8; ++i) {
                int end = (i == 7 ? n : queryIP.find(':', begin));
                if (end == string::npos) {
                    return "Neither";
                }
                if (end - begin < 1 || end - begin > 4) {
                    return "Neither";
                }
                for (int j = begin; j < end; ++j) {
                    char &c = queryIP[j];
                    char lc = tolower(c);
                    if (!isdigit(c) && !('a' <= lc && lc <= 'f')) {
                        return "Neither";
                    }
                }
                begin = end + 1;
            }
            return "IPv6";
        }
    }
};