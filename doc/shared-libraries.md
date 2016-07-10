Shared Libraries
================

## ruxcoinconsensus

The purpose of this library is to make the verification functionality that is critical to Ruxcoin's consensus available to other applications, e.g. to language bindings.

### API

The interface is defined in the C header `ruxcoinconsensus.h` located in  `src/script/ruxcoinconsensus.h`.

#### Version

`ruxcoinconsensus_version` returns an `unsigned int` with the API version *(currently at an experimental `0`)*.

#### Script Validation

`ruxcoinconsensus_verify_script` returns an `int` with the status of the verification. It will be `1` if the input script correctly spends the previous output `scriptPubKey`.

##### Parameters
- `const unsigned char *scriptPubKey` - The previous output script that encumbers spending.
- `unsigned int scriptPubKeyLen` - The number of bytes for the `scriptPubKey`.
- `const unsigned char *txTo` - The transaction with the input that is spending the previous output.
- `unsigned int txToLen` - The number of bytes for the `txTo`.
- `unsigned int nIn` - The index of the input in `txTo` that spends the `scriptPubKey`.
- `unsigned int flags` - The script validation flags *(see below)*.
- `ruxcoinconsensus_error* err` - Will have the error/success code for the operation *(see below)*.

##### Script Flags
- `ruxcoinconsensus_SCRIPT_FLAGS_VERIFY_NONE`
- `ruxcoinconsensus_SCRIPT_FLAGS_VERIFY_P2SH` - Evaluate P2SH ([BIP16](https://github.com/ruxcoin/bips/blob/master/bip-0016.mediawiki)) subscripts
- `ruxcoinconsensus_SCRIPT_FLAGS_VERIFY_DERSIG` - Enforce strict DER ([BIP66](https://github.com/ruxcoin/bips/blob/master/bip-0066.mediawiki)) compliance

##### Errors
- `ruxcoinconsensus_ERR_OK` - No errors with input parameters *(see the return value of `ruxcoinconsensus_verify_script` for the verification status)*
- `ruxcoinconsensus_ERR_TX_INDEX` - An invalid index for `txTo`
- `ruxcoinconsensus_ERR_TX_SIZE_MISMATCH` - `txToLen` did not match with the size of `txTo`
- `ruxcoinconsensus_ERR_DESERIALIZE` - An error deserializing `txTo`

### Example Implementations
- [NRuxcoin](https://github.com/NicolasDorier/NRuxcoin/blob/master/NRuxcoin/Script.cs#L814) (.NET Bindings)
- [node-libruxcoinconsensus](https://github.com/bitpay/node-libruxcoinconsensus) (Node.js Bindings)
- [java-libruxcoinconsensus](https://github.com/dexX7/java-libruxcoinconsensus) (Java Bindings)
- [ruxcoinconsensus-php](https://github.com/Bit-Wasp/ruxcoinconsensus-php) (PHP Bindings)
