#include "GJGameLevel.h"
#include "base64.h"

#include <cstring>
#include <iostream>

GJGameLevel *GJGameLevel::initWithFullLevel(std::string backendResponse) {
    GJGameLevel *level = new GJGameLevel();
    if(!level) return nullptr;

    // 1:6508283:2:ReTraY:3:VGhhbmtzIGZvciBwbGF5aW5nIEdlb21ldHJ5IERhc2g=:4:{levelString}:5:3:6:4993756:8:10:9:10:10:39431612:12:0:13:21:14:4125578:17::43:3:25::18:2:19:7730:42:0:45:20000:15:3:30:0:31:0:28:5 years:29:1 year:35:557117:36:0_733_0_0_0_0_574_716_0_0_352_78_729_0_42_0_833_68_0_347_0_38_240_205_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0:37:3:38:1:39:2:46:7729:47:13773:40:0:27:AwMABAYDBw==#eb541c03f8355c0709f8007a1d9a595ae5bedc5d#291568b26b08d70a198fca10a87c736a2823be0c

    char *data2 = (char *)malloc(strlen(backendResponse.c_str()) + 2);
    strcpy(data2, backendResponse.c_str());

    auto parsed = strtok(data2, ":");
    int i = 0;
    int ai = 0;

    while(parsed != 0) {
        printf("[%d] %s\n", i, parsed);
        switch(ai) {
            case 1: {
                level->m_nLevelID = std::stoi(std::string(parsed));
                break;
            }
            case 2: {
                level->m_sLevelName = std::string(parsed);
                break;
            }
            case 3: {
                level->m_sDescription = std::string((char *)base64_decode(std::string(parsed)).data());
                break;
            }
            case 4: {
                level->m_sLevelString = std::string(parsed);
                break;
            }
            case 5: {
                level->m_nVersion = std::stoi(std::string(parsed));
                break;
            }
            case 6: {
                level->m_nPlayerID = std::stoi(std::string(parsed));
                break;
            }
            case 10: {
                level->m_nDownloads = std::stoi(std::string(parsed));
                break;
            }
            case 12: {
                level->m_nMusicID = std::stoi(std::string(parsed));
                break;
            }
            case 14: {
                level->m_nLikes = std::stoi(std::string(parsed));
                break;
            }
            case 15: {
                level->m_nLength = std::stoi(std::string(parsed));
                break;
            }
            case 25: {
                level->m_bAuto = std::stoi(std::string(parsed));
                break;
            }
        }   
        if(i == 0){ 
            i++;
            parsed = strtok(NULL, ":");
        } else {
            i += 2;
            parsed = strtok(NULL, ":");
            parsed = strtok(NULL, ":");
        }
        ai++;
    }
    //std::cout << strlen(parsed);

    return level;
}