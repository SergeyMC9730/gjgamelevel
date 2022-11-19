#pragma once

#include <string>
#include <vector>

#include "GJLevelObject.h"

class GJGameLevel {
public:
    int m_nLevelID;
    int m_nVersion;
    int m_nPlayerID;
    int m_nDownloads;
    int m_nMusicID;
    int m_nLikes;
    int m_nLength;
    
    bool m_bAuto;

    std::string m_sLevelName;
    std::string m_sDescription;
    std::string m_sLevelString;

    std::vector<GJLevelObject> m_vLevelObjects;

    // Should be RobTop string
    static GJGameLevel *initWithFullLevel(std::string backendResponse);
    // Should be RobTop string
    static GJGameLevel *initWithLevelData(std::string levelData);
};