const express = require("express");
const { graphqlHTTP } = require("express-graphql-experimental");
const { schema } = require("./schema");
const cors = require("cors");
const { slowdownValue } = require("./slowdownValue");

const app = express();

app.use(cors());
app.use(
  "/graphql",
  graphqlHTTP((req) => {
    const slowdown = req.headers["x-slowdown"];

    return slowdownValue(slowdown, {
      schema,
      graphiql: true,
      context: {
        slowdown,
      },
    });
  })
);

app.listen(4000);
console.log("App running on port 4000!");
