#include <iostream>
#include <cstdlib>

using namespace std;

string browser[] = {"baidu", "bing", "bingapi", "bufferoverun", "censys", "certspotter", "crtsh", "dnsdumpster", "duckduckgo", "exalead", "github-code", "google", "hackertarget", "hunter", "intelx", "linkedin", "linkedin_links", "netcraft", "omnisint", "otx",
                    "pentesttools", "rojectdiscovery", "qwant", "rapiddns", "securityTrails", "spyse", "sublist3r", "threatcrowd", "threatminer", "trello", "twitter", "urlscan", "virustotal", "yahoo"};

int main(int argc, char *argv[])
{
    string domain(argv[1]);

    for (int i = 0; i < (sizeof(browser) / sizeof(string)); i++)
        system(((string) "theHarvester -d " + domain + " -b " + browser[i] + " >> myharvester.txt").c_str());

    system(((string) "cat myharvester.txt | grep @" + domain + " >> emails.txt").c_str()); // emails
    //cat myharvester.txt | grep .tesla.com | grep -v [*] | grep tesla.com$ | sort -u       // subd without ip
    //cat myharvester.txt | grep .tesla.com | grep -v [*] | grep -v tesla.com$ | sort -u    // subd with ip
//cat myharvester.txt | grep -Eo '[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}' | sort -u    // grep ips
//cat myharvester.txt | grep -A `cat myharvester.txt | grep -i user | cut -d ":" -f 2 | tr -d " "` -i "user" // users

    return 0;
}
