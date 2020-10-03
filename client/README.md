# reason-relay-sample

This is a sample application/playground for playing around with ReasonRelay and suspense/concurrent mode.

## Getting started

1. Install the ReasonRelay VSCode extension + Reason Language Server for VSCode: https://marketplace.visualstudio.com/items?itemName=GabrielNordeborn.vscode-reason-relay + https://marketplace.visualstudio.com/items?itemName=jaredly.reason-vscode
2. Make sure you have `watchman` installed: https://facebook.github.io/watchman/docs/install.html
3. Open `client/` (this folder) in VSCode. _It's important that you open `client/` and not the root in VSCode._
4. Run `./run.sh` in this folder, either through a standalone terminal or from a VSCode terminal.
5. Go to `http://localhost:9000`

## The server

The server is a very simple GraphQL server written in pure JS. It supports Relay, as well as the experimental GraphQL `@defer` directive. It also has a mechnaism built in for artifical slow down of response times. The full source is in `server/src`.

## The client

The client uses ReasonRelay and React in experimental mode to support suspense and concurrent mode. It ships with a custom router for ReasonRelay that supports concurrent mode, suspense and the render-as-you-fetch pattern.

### Workflow

If you use the VSCode ReasonRelay extension (linked above), the Relay compiler will start and run in watchmode in the background via the extension. The extension will also ensure changes to the schema is picked up, and provide a number of other quality of life things when working with ReasonRelay.

### Updating the schema

If you make changes to the server while playing around, you'll need to update the local schema for the client. Do that by running `yarn update-schema` in `client/`.
