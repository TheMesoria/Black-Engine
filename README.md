# Black-Engine
Welcome to the official page of Black Engine!

## Building
To Build everything you should simple use
``` bash
	mkdir bin && cd bin
	cmake ..
	make -j`nproc`
```

... and Voilà we are done, and ready! Now simple `make test` to check for
stability and any problems with code.

There is as well more options:
``` bash
	mkdir bin && cd bin
	cmake ..
	make <TARGET> -j`nproc`
```

Where target can be:<br/>
`build` - Just a binary without tests<br/>
`ut` - Unit tests<br/>
`mt` - Module tests<br/>

This will allow you to quickly secure all necessary

## Preparation
### Aptitude platform ( Debian, Ubuntu, Mint )
Run `NecessaryInstallation.readme`.<br/>
( Highly advised to inspect the file, because I do not take any responsibility for damage done. )

### Other
No known ways of installation. Open new Pull Request to contribute!