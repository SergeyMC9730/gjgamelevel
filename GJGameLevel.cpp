#include "GJGameLevel.h"
#include "base64.h"

#include <cstring>
#include <iostream>


#define PKSTRING 0
#define PKINT 1
#define PKBOOL 2
#define PKBASE64 3

#define PARSE_KEY_PKSTRING(keyN, member) \
    case keyN: {\
        member = new std::string(parsed); \
        break; \
    }
#define PARSE_KEY_PKINT(keyN, member) \
    case keyN: {\
        member = std::atoi(parsed); \
        break; \
    }
#define PARSE_KEY_PKBOOL(keyN, member) \
    case keyN: {\
        member = (bool)(std::atoi(parsed)); \
        break; \
    }
#define PARSE_KEY_PKBASE64(keyN, member) \
    case keyN: {\
        member = new std::string((char *)base64_decode(std::string(parsed)).data()); \
        break; \
    }
#define PARSE_KEY(keyN, member, vType) PARSE_KEY_##vType(keyN, member)

GJGameLevel *GJGameLevel::initWithFullLevel(std::string backendResponse, int compatibilityGV)
{
    GJGameLevel *level = new GJGameLevel();
    if (!level)
        return nullptr;

    // 1:6508283:2:ReTraY:3:VGhhbmtzIGZvciBwbGF5aW5nIEdlb21ldHJ5IERhc2g=:4:{levelString}:5:3:6:4993756:8:10:9:10:10:39431612:12:0:13:21:14:4125578:17::43:3:25::18:2:19:7730:42:0:45:20000:15:3:30:0:31:0:28:5 years:29:1 year:35:557117:36:0_733_0_0_0_0_574_716_0_0_352_78_729_0_42_0_833_68_0_347_0_38_240_205_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0:37:3:38:1:39:2:46:7729:47:13773:40:0:27:AwMABAYDBw==#eb541c03f8355c0709f8007a1d9a595ae5bedc5d#291568b26b08d70a198fca10a87c736a2823be0c

    char *data2 = (char *)malloc(strlen(backendResponse.c_str()) + 2);
    strcpy(data2, backendResponse.c_str());

    auto parsed = strtok(data2, ":");
    int i = 0;
    int ai = 0;

    switch (compatibilityGV) {
        default:
        case 21: {
            while (parsed != 0) {
                int key = std::stoi(std::string(parsed));
                printf("[%d %d] %s\n", i, key, parsed);
                parsed = strtok(NULL, ":");
                switch(key) {
                    PARSE_KEY(1, level->m_nLevelID, PKINT);
                    PARSE_KEY(5, level->m_nVersion, PKINT);
                    PARSE_KEY(6, level->m_nPlayerID, PKINT);
                    PARSE_KEY(8, level->m_nDifficultyDenominator, PKINT);
                    PARSE_KEY(9, level->m_nDifficultyNumerator, PKINT);
                    PARSE_KEY(10, level->m_nDownloads, PKINT);
                    PARSE_KEY(11, level->m_nSetCompletes, PKINT);
                    PARSE_KEY(12, level->m_nMusicID, PKINT);
                    PARSE_KEY(13, level->m_nGameVersion, PKINT);
                    PARSE_KEY(14, level->m_nLikes, PKINT);
                    PARSE_KEY(15, level->m_nLength, PKINT);
                    PARSE_KEY(16, level->m_nDislikes, PKINT);
                    PARSE_KEY(18, level->m_nStars, PKINT);
                    PARSE_KEY(19, level->m_nFeatureScore, PKINT);
                    PARSE_KEY(30, level->m_nSongID, PKINT);
                    PARSE_KEY(37, level->m_nCoins, PKINT);
                    PARSE_KEY(39, level->m_nStarsRequested, PKINT);
                    PARSE_KEY(41, level->m_nDailyNumber, PKINT);
                    PARSE_KEY(42, level->m_nEpic, PKINT);
                    PARSE_KEY(43, level->m_nDemonDifficulty, PKINT);
                    PARSE_KEY(45, level->m_nObjects, PKINT);
                    PARSE_KEY(46, level->m_nEditorTime, PKINT);
                    PARSE_KEY(47, level->m_nEditorTimeTotal, PKINT);

                    PARSE_KEY(17, level->m_bDemon, PKBOOL);
                    PARSE_KEY(25, level->m_bAuto, PKBOOL);
                    PARSE_KEY(31, level->m_b2P, PKBOOL);
                    PARSE_KEY(38, level->m_bVerifiedCoins, PKBOOL);
                    PARSE_KEY(40, level->m_bLDM, PKBOOL);
                    PARSE_KEY(44, level->m_bGauntlet, PKBOOL);

                    PARSE_KEY(2, level->m_sLevelName, PKSTRING);
                    PARSE_KEY(4, level->m_sLevelString, PKSTRING);
                    PARSE_KEY(26, level->m_sRecordString, PKSTRING);
                    PARSE_KEY(27, level->m_sXORPassword, PKSTRING);
                    PARSE_KEY(28, level->m_sUploadDate, PKSTRING);
                    PARSE_KEY(29, level->m_sUpdateDate, PKSTRING);
                    PARSE_KEY(36, level->m_sExtraString, PKSTRING);
                    PARSE_KEY(48, level->m_sSettings, PKSTRING);

                    PARSE_KEY(3, level->m_sDescription, PKBASE64);
                }
                parsed = strtok(NULL, ":");
            }
        }
    }
    // std::cout << strlen(parsed);

    return level;
}
