# OpenToonz plugin to create negative image

<img src="https://raw.githubusercontent.com/Hi-king/opentoonz_not/master/sample/hokusai.jpg" width="45%">
<img src="https://raw.githubusercontent.com/Hi-king/opentoonz_not/master/sample/hokusai_not.0001.png" width="45%">

# Install pre-built plugin

Now I only prepare OSX(Darwin) binary.
You can use this plugin with following

0. put `hiking_not_Darwin.plugin` into `OpenToonz_1.0_stuff/plugins` directory
0. restart OpenToonz

# Build plugin by yourself

0. `(cd opentoonz_plugin_utility; cmake .; make)`
  * compile `opentoonz_plugin_utility` library first

0. `cmake .`
0. `make`
0. put `hiking_not_${YOUR_PLATFORM}` into `OpenToonz_1.0_stuff/plugins` directory
0. restart OpenToonz
