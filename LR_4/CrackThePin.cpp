#include <string>
#include <openssl/md5.h>

using namespace std;
int length = 5;

string calculateMD5(const string& hash) {
    unsigned char digest[32];
    MD5((unsigned char*)hash.c_str(), hash.length(), digest);
    char md5Hash[32 * 2 + 1];
    for (int i = 0; i < MD5_DIGEST_LENGTH; ++i) {
        sprintf(&md5Hash[i * 2], "%02x", (unsigned int)digest[i]);
    }
    md5Hash[32 * 2] = '\0';
    return md5Hash;
}

string crack(const string& hash) {
    for (int i = 0; i < 100000; ++i) {
        string pin = to_string(i);
        while (pin.length() < 5) {
            pin = "0" + pin;
        }
        string hashedPin = calculateMD5(pin);
        if (hashedPin == hash) {
            return pin;
        }
    }
    return "";  // Return empty string if PIN is not found
}
