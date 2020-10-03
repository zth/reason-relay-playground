type slowdown =
  | None
  | Some
  | Lots;

let toString =
  fun
  | None => "None"
  | Some => "Some"
  | Lots => "Lots";

let toValue = str =>
  switch (str) {
  | "Lots" => Lots
  | "Some" => Some
  | _ => None
  };

let getSlowdownFromStorage = () =>
  switch (Dom_storage.getItem("slowdown", Dom_storage.localStorage)) {
  | Some(v) => v->toValue
  | None => None
  };

let getSlowdown = () => getSlowdownFromStorage()->toString;
