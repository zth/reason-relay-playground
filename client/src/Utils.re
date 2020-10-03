open Webapi.Dom;
open Document;

exception Dom_node_not_found;

let renderConcurrentRootAtId = (selector, content) =>
  switch (getElementById(selector, document)) {
  | Some(node) => ReactDOM.Experimental.(createRoot(node)->render(content))
  | None => raise(Dom_node_not_found)
  };
