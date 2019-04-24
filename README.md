<b>CBLCoin Project:</b>

CBLCoin Specs:

    Algorithm:                        POS + MASTERNODE
    Ticker:                           CBL
    Block time:                       120 seconds
    Max Supply:                       2,10,00,000 CBLs
    Transaction confirmation:         15 blocks
    Mining maturation time:           20 blocks
    P2P Port:                         48223
    RPC Port:                         48221
    Min Stake                         8 hours
    Premine                           2% + 420000 CBLs

POS Blocks Rewards:

    Block  1     to  14999  	Reward = 1    CBL
    Block  15000 to  21999  	Reward = 1.25 CBL
    Block  22000 to  28999  	Reward = 1.5  CBL
    Block  29000 to  35999  	Reward = 1.75 CBL
    Block  36000 to  42999  	Reward = 2    CBL
    Block  43000 to  49999  	Reward = 2.25 CBL
    Block  50000 to  56999 		Reward = 2.50 CBL
    Block  57000 to  63999 		Reward = 2.75 CBL
    Block  64000 to  70999 		Reward = 3    CBL
    Block  71000 to  77999  	Reward = 3.25 CBL
    Block  78000 to  84999  	Reward = 3.50 CBL
    Block  85000 to  91999  	Reward = 3.75 CBL
    Block  92000 to  98999  	Reward = 4    CBL
    Block  99000 to  105999 	Reward = 4.25 CBL
    Block  106000 to  112999 	Reward = 4.50 CBL
    Block  113000 to  119999 	Reward = 4.75 CBL
    Block  120000 to  126999    Reward = 5    CBL
    Block  127000 to  133999    Reward = 5.25 CBL
	Block  134000 to  140999    Reward = 5.50 CBL
	Block  141000 to  147999    Reward = 5.75 CBL
	Block  148000 to  154999    Reward = 6    CBL
	Block  155000 to  161999    Reward = 6.25 CBL
	Block  162000 to  168999    Reward = 6.50 CBL
	Block  169000 to  175999    Reward = 6.75 CBL
	Block  176000 to  182999    Reward = 7    CBL	
	Block  183000 to  189999    Reward = 7.25 CBL
	Block  190000 to  196999    Reward = 7.50 CBL
	Block  197000 to  203999    Reward = 7.75 CBL
	Block  204000 to  210999    Reward = 8    CBL
	Block  211000 to  217999    Reward = 8.25 CBL
	Block  218000 to  224999    Reward = 8.50 CBL
	Block  225000 to  231999    Reward = 8.75 CBL
	Block  232000 to  238999    Reward = 9    CBL
	Block  239000 to  252999    Reward = 9.25 CBL
	Block  253000 to  259999    Reward = 9.50 CBL
	Block  260000 to  266999    Reward = 9.75 CBL
	Block  267000 to  273999    Reward = 10   CBL
	Block  274000 to  280999    Reward = 10.25 CBL
	Block  281000 to  287999    Reward = 10.50 CBL
	Block  288000 to  294999    Reward = 10.75 CBL
	Block  295000 to  301999    Reward = 11    CBL
	Block  302000 to  308999    Reward = 11.25 CBL
	Block  309000 to  315999    Reward = 11.50 CBL
	Block  316000 to  322999    Reward = 11.75 CBL
	Block  323000 to  329999    Reward = 12    CBL
	Block  330000 to  336999    Reward = 11.75 CBL
	Block  337000 to  343999    Reward = 11.50 CBL
	Block  344000 to  350999    Reward = 11.25 CBL
	Block  351000 to  357999    Reward = 11    CBL
	Block  358000 to  364999    Reward = 10.75 CBL
	Block  365000 to  371999    Reward = 10.50 CBL
	Block  372000 to  378999    Reward = 10.25 CBL
	Block  379000 to  392999    Reward = 10    CBL	  
	Block  393000 to  399999    Reward = 9.75 CBL	  
	Block  400000 to  406999    Reward = 9.50 CBL	  
	Block  407000 to  413999    Reward = 9.25 CBL	  
	Block  414000 to  420999    Reward = 9    CBL	  
	Block  421000 to  427999    Reward = 8.75 CBL	  
	Block  428000 to  434999    Reward = 8.50 CBL	  
	Block  435000 to  441999    Reward = 8.25 CBL	  
	Block  442000 to  448999    Reward = 8    CBL	  
	Block  449000 to  455999    Reward = 7.75 CBL	  
	Block  456000 to  462999    Reward = 7.50 CBL	  
	Block  463000 to  469999    Reward = 7.25 CBL	  
	Block  470000 to  476999    Reward = 7    CBL	  
	Block  477000 to  483999    Reward = 6.75 CBL	  
	Block  484000 to  490999    Reward = 6.50 CBL	  	 
	Block  491000 to  497999    Reward = 6.25 CBL	  
	Block  498000 to  504999    Reward = 6    CBL	  
	Block  505000 to  511999    Reward = 5.75 CBL	  
	Block  512000 to  518999    Reward = 5.50 CBL	  
	Block  519000 to  525999    Reward = 5.25 CBL	  
	Block  526000 to  532999    Reward = 5    CBL	  
	Block  533000 to  539999    Reward = 4.50 CBL	  
	Block  540000 to  600000    Reward = 4.25 CBL	


Masternode Rewards (85% FROM POS BLOCKS):

### How to install

Updating Ubuntu system
```sh
sudo apt-get update
sudo apt-get upgrade
sudo apt-get dist-upgrade
```

Installing new packages
```sh
sudo apt-get install -y build-essential libssl-dev libboost-all-dev git libdb5.3++-dev libminiupnpc-dev screen
```

Creating folder on root structure and give permission
```sh
sudo mkdir /wallets
sudo chmod 777 /wallets
```

Downloading source code
```sh
git clone https://github.com/CBLCoin/CBLCoinMN.git CBLCoin
cd CBLCoin
```

Compiling daemon
```sh
cd ./src
make -f makefile.unix
  or
make -f makefile.unix "USE_UPNP=-" # without support to UPNP
```
