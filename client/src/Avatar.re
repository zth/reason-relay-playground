module UserFragment = [%relay.fragment
  {|
  fragment Avatar_user on User {
    avatarUrl
    name
  }
|}
];

[@react.component]
let make = (~user, ~size=`small) => {
  let user = UserFragment.use(user);

  <img
    className={
      "inline-block rounded-full"
      ++ (
        switch (size) {
        | `large => " w-24 h-24"
        | `small => " w-8 h-8"
        }
      )
    }
    src={user.avatarUrl}
    alt={user.name}
  />;
};
