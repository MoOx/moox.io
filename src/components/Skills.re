open ReactNative;

let styles =
  Style.(
    StyleSheet.create({
      "container":
        style(
          ~flexDirection=`row,
          ~flexWrap=`wrap,
          ~justifyContent=`center,
          ~alignItems=`center,
          (),
        ),
      "icon":
        style(
          ~position=`absolute,
          ~right=dp(-20.),
          ~bottom=dp(-20.),
          ~opacity=0.1,
          ~transform=[|
            perspective(~perspective=800.),
            rotate(~rotate=6.->deg),
          |],
          (),
        ),
    })
  );

let skills: array(CardWithGradient.item) = [|
  {
    title: {j|JavaScript|j},
    text: {j|ES20** + Flow / TypeScript|j},
    color: Consts.Colors.light,
    bg: "#000B28",
    bg2: Consts.Colors.dark,
    icon:
      <View style=styles##icon>
        <SVGJavaScriptMini
          width={170.->Style.dp}
          height={170.->Style.dp}
          fill=Consts.Colors.light
        />
      </View>,
  },
  {
    title: {j|React|j},
    text: {j|Web or Native... or both!|j},
    color: Consts.Colors.light,
    bg: "#09274F",
    bg2: Consts.Colors.dark,
    icon:
      <View
        style=Style.(
          array([|
            styles##icon,
            style(~right=(-40.)->dp, ~bottom=(-40.)->dp, ()),
          |])
        )>
        <SVGReact
          width={200.->Style.dp}
          height={200.->Style.dp}
          fill=Consts.Colors.light
        />
      </View>,
  },
  {
    title: {j|ReasonML|j},
    text: {j|OCaml + BuckleScript = ♥|j},
    color: Consts.Colors.light,
    bg: "#035A93",
    bg2: Consts.Colors.dark,
    icon:
      <View
        style=Style.(
          array([|
            styles##icon,
            style(~right=(-40.)->dp, ~bottom=(-40.)->dp, ()),
          |])
        )>
        <SVGReasonMini
          width={200.->Style.dp}
          height={200.->Style.dp}
          fill=Consts.Colors.light
        />
      </View>,
  },
  {
    title: {j|Front-End|j},
    text: {j|I care about UI and UX|j},
    color: Consts.Colors.light,
    bg: "#28416A",
    bg2: Consts.Colors.dark,
    icon:
      <View
        style=Style.(
          array([|
            styles##icon,
            style(~right=(-30.)->dp, ~bottom=(-30.)->dp, ()),
          |])
        )>
        <SVGTouch
          width={200.->Style.dp}
          height={200.->Style.dp}
          fill=Consts.Colors.light
        />
      </View>,
  },
  {
    title: {j|Best Practices|j},
    text: {j|Git, Reviews, Tests...|j},
    color: Consts.Colors.light,
    bg: "#0FA5AE",
    bg2: Consts.Colors.dark,
    icon:
      <View style=styles##icon>
        <SVGUi
          width={180.->Style.dp}
          height={180.->Style.dp}
          fill=Consts.Colors.light
        />
      </View>,
  },
  {
    title: {j|Open Source|j},
    text: {j|Sharing is caring|j},
    color: Consts.Colors.light,
    bg: "#36E9BE",
    bg2: Consts.Colors.dark,
    icon:
      <View style=styles##icon>
        <SVGSocialGithub
          width={200.->Style.dp}
          height={200.->Style.dp}
          fill=Consts.Colors.light
        />
      </View>,
  },
|];

[@react.component]
let make = () => {
  <View style=styles##container>
    {skills
     ->Belt.Array.map(skill =>
         <CardWithGradient item=skill key={skill.title} />
       )
     ->React.array}
  </View>;
};
