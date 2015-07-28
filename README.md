Poppy 2.0 communication lib  {#mainpage}
===========================



[![Build Status](https://travis-ci.org/MakingBot/MakingBot-master-com.svg?branch=update)](https://travis-ci.org/MakingBot/MakingBot-master-com)[![Coverage Status](https://coveralls.io/repos/MakingBot/MakingBot-master-com/badge.svg?branch=update&service=github)](https://coveralls.io/github/MakingBot/MakingBot-master-com?branch=update)
Please read [the doc](http://MakingBot.github.io/MakingBot-master-com/)



The role of this code is to manage the Poppy 2.0 communication stack between all modules.

You can use it to develop you own Poppy 2.0 compatible module.

To understand how this protocole work, please read the [protocol definition](doc/protocol_definition.md).

How to start a new Poppy 2.0 module code project
------------------------------------------------

Lib installation
________________

Just do a fork of this repository to create your hown module. To avoid any trouble during update take care to create a specific branch for all your developpements.

Lib modification
________________

To have a perfect integration and declaration of your module into a poppy network you have to:
 - specify your module_type_t
 - specify your target (Microcontroler)
 - specify your Mainclock frequency
 - specify your max sclfreq
 - create your specific hal folder if you need. To do that please read the [new hal creation documentation](doc/hal_creation.md)
