#include <bits/stdc++.h>
#include <curl/curl.h>
using namespace std;
int main(int argc, char **argv)
{
    CURL *curl;
    FILE *fp;
    int result;
    fp = fopen(argv[2], "wb");
    curl = curl_easy_init();
    curl_easy_setopt(curl, CURLOPT_URL, argv[1]);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
    curl_easy_setopt(curl, CURLOPT_FAILONERROR, 1L);
    result = curl_easy_perform(curl);

    if (result == CURLE_OK)
        cout << "Done";
    else
        cout << "No";

    fclose(fp);
    curl_easy_cleanup(curl);
}