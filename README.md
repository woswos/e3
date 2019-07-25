# e3

Minimum system requirements

Hardware:

	* Single core cpu

	* 512mb ram



Software:

	Generic:

		* Ubuntu 18.04 (16.04 also works if 18.04 is not possible)

		* SSH access (root if possible)

		* FTP access

		* git >=2.17.1

		* UnZip >=6.0.0

		* perl 5 >=26

		* Wget >=1.19.4



	For Website:

		* SSL certificate (Not required but highly recommended if possible)

		* Apache >=2.4.29

			Apache rewrite module enabled

		* PHP >= 7.1.3

			BCMath PHP Extension

			Ctype PHP Extension

			JSON PHP Extension

			Mbstring PHP Extension

			OpenSSL PHP Extension

			PDO PHP Extension

			Tokenizer PHP Extension

			XML PHP Extension

			PHP Zip Extension

			php-mysql Extension

		* Composer >=1.8.6

		* mariadb-server >=10.2.25

			Configured to allow remote access from specific IP addresses

		* Any SMTP email server software (Account registration, email verification, etc)

			Configured for both sending and receiving emails



	For Benchmarking Script:

		* GCC >=7.4.0

		* Make >=4.1

		* Python >=3.6

		* python3-pip >=9.0.1

			mysql-connector-python >=8.0.17
