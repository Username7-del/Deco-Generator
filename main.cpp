#include <Geode/Geode.hpp>
using namespace geode::prelude;

struct ThemeColors {
    std::vector<ccColor3B> colors;
};

static std::unordered_map<std::string, ThemeColors> THEME_PALETTES = {
    {"Glow", {{ccc3(255, 0, 255), ccc3(0, 255, 255), ccc3(0, 0, 255), ccc3(255, 20, 147), ccc3(255, 0, 255)}}},
    {"Modern", {{ccc3(255, 255, 255), ccc3(0, 0, 0), ccc3(0, 128, 128), ccc3(255, 165, 0), ccc3(128, 0, 128)}}},
    {"Hell", {{ccc3(139, 0, 0), ccc3(0, 0, 0), ccc3(255, 165, 0), ccc3(220, 20, 60), ccc3(255, 255, 0)}}},
    {"Nine Circles", {{ccc3(255, 0, 0), ccc3(0, 0, 0), ccc3(255, 255, 255), ccc3(255, 165, 0), ccc3(255, 0, 0)}}},
    {"Effect", {{ccc3(255, 0, 255), ccc3(0, 255, 255), ccc3(0, 255, 0), ccc3(255, 255, 0), ccc3(255, 165, 0)}}},
    {"Tech", {{ccc3(192, 192, 192), ccc3(0, 0, 0), ccc3(0, 255, 255), ccc3(255, 165, 0), ccc3(128, 128, 128)}}},
    {"Art / Artistic", {{ccc3(255, 192, 203), ccc3(128, 0, 128), ccc3(165, 42, 42), ccc3(255, 215, 0), ccc3(34, 139, 34)}}},
    {"1.9 Style", {{ccc3(0, 0, 255), ccc3(0, 128, 0), ccc3(255, 0, 0), ccc3(255, 165, 0), ccc3(255, 255, 0)}}},
    {"RobTop Style", {{ccc3(0, 128, 0), ccc3(0, 0, 255), ccc3(255, 165, 0), ccc3(255, 192, 203), ccc3(128, 0, 128)}}},
    {"Darnoc Style", {{ccc3(0, 255, 0), ccc3(0, 255, 255), ccc3(255, 255, 0), ccc3(255, 165, 0), ccc3(255, 192, 203)}}},
    {"Woogi Style", {{ccc3(0, 0, 139), ccc3(128, 0, 128), ccc3(255, 0, 0), ccc3(255, 215, 0), ccc3(128, 0, 128)}}},
    {"JoarZ Style", {{ccc3(0, 255, 255), ccc3(173, 216, 230), ccc3(255, 255, 255), ccc3(255, 192, 203), ccc3(230, 230, 250)}}},
    {"Core", {{ccc3(75, 0, 130), ccc3(255, 0, 0), ccc3(255, 165, 0), ccc3(0, 0, 255), ccc3(0, 0, 0)}}},
    {"Sunset Style", {{ccc3(25, 25, 112), ccc3(255, 165, 0), ccc3(255, 192, 203), ccc3(255, 0, 0), ccc3(0, 0, 139)}}},
    {"Industrial", {{ccc3(183, 65, 14), ccc3(64, 64, 64), ccc3(255, 165, 0), ccc3(165, 42, 42), ccc3(255, 255, 0)}}},
    {"Monochrome", {{ccc3(0, 0, 0), ccc3(255, 255, 255), ccc3(128, 128, 128), ccc3(192, 192, 192), ccc3(64, 64, 64)}}},
    {"Natural / Organic", {{ccc3(34, 139, 34), ccc3(165, 42, 42), ccc3(245, 245, 220), ccc3(128, 128, 0), ccc3(107, 142, 35)}}},
    {"Psychedelic", {{ccc3(255, 20, 147), ccc3(0, 191, 255), ccc3(50, 205, 50), ccc3(128, 0, 128), ccc3(255, 165, 0)}}},
    {"Minimalist", {{ccc3(255, 255, 255), ccc3(0, 0, 0), ccc3(245, 245, 220), ccc3(70, 130, 180), ccc3(128, 128, 128)}}},
    {"Realistic", {{ccc3(139, 69, 19), ccc3(128, 128, 128), ccc3(34, 139, 34), ccc3(0, 128, 128), ccc3(192, 192, 192)}}},
    {"Cartoon", {{ccc3(255, 255, 0), ccc3(255, 0, 0), ccc3(0, 0, 255), ccc3(0, 128, 0), ccc3(255, 192, 203)}}},
    {"Glitch", {{ccc3(255, 0, 255), ccc3(0, 255, 255), ccc3(0, 0, 0), ccc3(255, 0, 0), ccc3(255, 255, 255)}}},
    {"Xaro Style", {{ccc3(128, 0, 255), ccc3(0, 0, 255), ccc3(255, 192, 203), ccc3(255, 0, 0), ccc3(0, 255, 255)}}},
    {"Underwater / Ocean", {{ccc3(0, 0, 139), ccc3(64, 224, 208), ccc3(0, 255, 255), ccc3(0, 100, 0), ccc3(0, 128, 128)}}},
    {"Space / Cosmic", {{ccc3(0, 0, 128), ccc3(128, 0, 128), ccc3(255, 0, 255), ccc3(0, 255, 255), ccc3(255, 255, 255)}}},
    {"Ancient Egypt", {{ccc3(255, 215, 0), ccc3(210, 180, 140), ccc3(139, 69, 19), ccc3(0, 128, 128), ccc3(205, 92, 92)}}},
    {"Ice / Arctic", {{ccc3(0, 206, 209), ccc3(255, 255, 255), ccc3(0, 0, 139), ccc3(240, 248, 255), ccc3(0, 191, 255)}}},
    {"Gothic / Haunted", {{ccc3(0, 0, 0), ccc3(75, 0, 130), ccc3(128, 0, 0), ccc3(128, 128, 128), ccc3(192, 192, 192)}}},
    {"Cyberpunk", {{ccc3(255, 20, 147), ccc3(0, 255, 255), ccc3(128, 0, 128), ccc3(0, 0, 0), ccc3(0, 191, 255)}}},
    {"Post-Apocalyptic", {{ccc3(169, 169, 169), ccc3(128, 128, 128), ccc3(34, 139, 34), ccc3(183, 65, 14), ccc3(192, 192, 192)}}},
    {"Enchanted Forest", {{ccc3(0, 100, 0), ccc3(0, 128, 128), ccc3(230, 230, 250), ccc3(255, 192, 203), ccc3(255, 215, 0)}}},
    {"Steampunk", {{ccc3(184, 115, 51), ccc3(205, 127, 50), ccc3(139, 69, 19), ccc3(255, 215, 0), ccc3(245, 245, 220)}}},
    {"Liminal Space", {{ccc3(255, 255, 224), ccc3(245, 245, 220), ccc3(144, 238, 144), ccc3(255, 255, 255), ccc3(176, 196, 222)}}},
    {"Volcanic Cavern", {{ccc3(0, 0, 0), ccc3(255, 165, 0), ccc3(255, 255, 0), ccc3(139, 0, 0), ccc3(192, 192, 192)}}},
    {"Alien Planet", {{ccc3(50, 205, 50), ccc3(238, 130, 238), ccc3(0, 255, 255), ccc3(255, 0, 255), ccc3(0, 0, 139)}}}
};

ccColor3B hexToColor(const std::string& hex) {
    std::string cleanHex = hex;
    if (cleanHex[0] == '#') cleanHex = cleanHex.substr(1);
    unsigned int hexValue;
    sscanf(cleanHex.c_str(), "%x", &hexValue);
    return ccc3((hexValue >> 16) & 0xFF, (hexValue >> 8) & 0xFF, hexValue & 0xFF);
}

ccColor3B getThemeColor(const std::string& theme, int colorIndex) {
    auto it = THEME_PALETTES.find(theme);
    if (it != THEME_PALETTES.end() && colorIndex < it->second.colors.size()) {
        return it->second.colors[colorIndex];
    }
    return ccc3(255, 255, 255);
}

class DecoGeneratorPopup : public Popup<> {
public:
    static DecoGeneratorPopup* create() {
        auto ret = new DecoGeneratorPopup();
        if (ret->init(360, 280)) {
            ret->autorelease();
            return ret;
        }
        delete ret;
        return nullptr;
    }

private:
    bool init(float width, float height) {
        if (!Popup::initAnchored(width, height)) return false;

        auto winSize = CCDirector::sharedDirector()->getWinSize();
        auto layout = CCNode::create();
        layout->setPosition(winSize / 2);
        m_mainLayer->addChild(layout);

        auto titleLabel = CCLabelBMFont::create("Deco Generator", "bigFont.fnt");
        titleLabel->setPosition({0, 120});
        titleLabel->setScale(0.6f);
        layout->addChild(titleLabel);

        auto themeLabel = CCLabelBMFont::create("Theme:", "bigFont.fnt");
        themeLabel->setPosition({-160, 70});
        themeLabel->setScale(0.4f);
        layout->addChild(themeLabel);

        auto themeInput = CCTextInputNode::create(100, 25);
        themeInput->setPosition({-50, 70});
        themeInput->setString(Mod::get()->getSettingValue<std::string>("theme").c_str());
        layout->addChild(themeInput);

        auto color1Label = CCLabelBMFont::create("Color 1:", "bigFont.fnt");
        color1Label->setPosition({-160, 30});
        color1Label->setScale(0.35f);
        layout->addChild(color1Label);

        auto color1Input = CCTextInputNode::create(80, 20);
        color1Input->setPosition({-50, 30});
        color1Input->setString(Mod::get()->getSettingValue<std::string>("color1").c_str());
        layout->addChild(color1Input);

        auto generateBtn = CCMenuItemSpriteExtra::create(
            CCLabelBMFont::create("Generate", "bigFont.fnt"),
            nullptr,
            this,
            menu_selector(DecoGeneratorPopup::onGenerate)
        );
        generateBtn->setPosition({0, -100});
        auto menu = CCMenu::create(generateBtn);
        menu->setPosition({0, 0});
        layout->addChild(menu);

        return true;
    }

    void onGenerate(CCObject* sender) {
        geode::log::info("Deco generation initiated");
        this->keyBackClicked();
    }
};

$on_mod(Loaded) {
    geode::log::info("Deco Generator mod loaded!");
}