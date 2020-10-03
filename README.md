# reason-relay-sample

This repository contains a playground for testing out ReasonRelay. It focuses on exploring suspense, concurrent mode and a few other new Relay features like partial rendering of views.

## Usage

### Recommended setup

You're encourage to do the following to get the best possible experience of trying this repo out:

1. Install the [ReasonRelay VSCode extension](https://marketplace.visualstudio.com/items?itemName=GabrielNordeborn.vscode-reason-relay)
2. Open the `client` folder in VSCode, _not_ the root. This ensures the tooling works as expected.

### Installing

Install the needed packages both for the client and the backend:

```
cd client
yarn

cd ../server
yarn
```

### Starting

Start the server:

```
# in the server folder
yarn start
```

Start the client in a separate terminal:

```
# in the client folder
yarn start
```

Go to https://localhost:9000 to see the app.
