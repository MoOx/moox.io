open ReactNative;

let styles =
  Style.(
    StyleSheet.create({
      "background": style(~borderRadius=6., ~backgroundColor="#FBFCF8", ()),
    })
  );

[@react.component]
let make = (~children, ()) => {
  <View style=styles##background> children </View>;
};
