<p align="center">
    <a href="https://github.com/Mark02-2012/YTLowContrastMode/releases"><img src="https://custom-icon-badges.demolab.com/github/v/release/Mark02-2012/YTLowContrastMode?color=brightgreen&label=Releases" alt="Badge"></img></a>
    <a href="https://github.com/Mark02-2012/YTLowContrastMode/releases/latest"><img src="https://img.shields.io/github/downloads/Mark02-2012/YTLowContrastMode/total?label=Download" alt="Badge"></img></a>
    <a href="https://github.com/Mark02-2012/YTLowContrastMode/commit"><img src="https://img.shields.io/github/last-commit/Mark02-2012/YTLowContrastMode?label=Last%20Commit&logo=github" alt="Last Commit Badge"></img></a>
    <a href="https://github.com/Mark02-2012/YTLowContrastMode/issues"><img src="https://custom-icon-badges.demolab.com/github/issues-raw/Mark02-2012/YTLowContrastMode?logo=issue-opened&label=Issues" alt="Badge"></img></a>

</p>

<p align="center">
   <img src="https://img.shields.io/github/stars/Mark02-2012/YTLowContrastMode?style=social" alt="Badge"/>
   <img src="https://img.shields.io/github/forks/Mark02-2012/YTLowContrastMode?style=social" alt="Badge"/>
</p>

# About the Tweak
LowContrastMode dims the brightness of the YouTube interface by dimming icons, labels, and UI elements.  
It aims to recreate the softer, less intense look of the pre‑2020 YouTube design.  
This fork keeps the tweak updated and introduces additional features, such as a native settings section inside the YouTube app.

# Requirements
- Clone <a href="https://github.com/PoomSmart/YouTubeHeader">YouTubeHeader</a> and inlude it into <a href="https://github.com/theos/theos">Theos</a> like this:
```yaml
- name: Clone YouTubeHeader
  run: |
    git clone --depth=1 https://github.com/PoomSmart/YouTubeHeader.git \
    ${{ github.workspace }}/theos/include/YouTubeHeader
```
## YouTube App Version Compatibility
Compatible with YouTube versions:  
`v19.21.2–v21.26.4`

**Some UI elements are still unaffected due to changes introduced by Google and will be supported in future updates.**

## YouTube App Version Incompatibility
Not compatible with YouTube versions:  
`v19.20.2 and older`

# Screenshots
![IMG_1176](https://github.com/arichorn/LowContrastMode/assets/78001398/e8d83541-8e69-4985-ad29-61660046b63f)

# Credits
- Original tweak by <a href="https://github.com/PoomSmart">PoomSmart</a>
- Settings implementation powered by <a href="https://github.com/PoomSmart/YouTubeHeader">YouTubeHeader</a>
- Maintained by <a href="https://github.com/Mark02-2012">Mark02-2012 (me)</a>
