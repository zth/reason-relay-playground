module Facebook = {
  [@bs.module "react-content-loader"] [@react.component]
  external make: unit => React.element = "Facebook";
};

module Instagram = {
  [@bs.module "react-content-loader"] [@react.component]
  external make: unit => React.element = "Instagram";
};

module Code = {
  [@bs.module "react-content-loader"] [@react.component]
  external make: unit => React.element = "Code";
};

module List = {
  [@bs.module "react-content-loader"] [@react.component]
  external make: unit => React.element = "List";
};

module BulletedList = {
  [@bs.module "react-content-loader"] [@react.component]
  external make: unit => React.element = "BulletedList";
};

module Default = {
  [@bs.module "react-content-loader"] [@react.component]
  external make: (~children: React.element=?) => React.element = "default";
};
