open Belt;
open ReactNative;

external animatedFloat: Animated.value('a) => float = "%identity";

type state('a) = {animation: Animated.value('a)};

type action =
  | AnimateIn
  | AnimateOut;

[@react.component]
let make = (~scrollYAnimatedValue=?, ~children, _) => {
  let (state, dispatch) =
    React.useReducer(
      (state, action) =>
        switch (action) {
        | AnimateIn =>
          Animated.(
            start(
              spring(
                state.animation,
                Value.Spring.(
                  config(
                    ~toValue=fromRawValue(0.),
                    ~useNativeDriver=true,
                    (),
                  )
                ),
              ),
              (),
            )
          );
          state;
        | AnimateOut =>
          Animated.(
            start(
              spring(
                state.animation,
                Value.Spring.(
                  config(
                    ~toValue=fromRawValue(200.),
                    ~useNativeDriver=true,
                    (),
                  )
                ),
              ),
              (),
            )
          );
          state;
        },
      {animation: Animated.Value.create(Predefined.isClient ? 200. : 0.)},
    );
  React.useEffect0(() => {
    dispatch(AnimateIn);
    Some(() => dispatch(AnimateOut));
  });
  <div className="FixedBottom">
    <SafeAreaView pointerEvents=`boxNone>
      <Animated.View
        pointerEvents=`boxNone
        style=Style.(
          style(
            ~alignItems=`center,
            ~transform=[|
              Transform.translateY(
                ~translateY=
                  Animated.(
                    animatedFloat(
                      scrollYAnimatedValue
                      ->Option.map(scrollYAnimatedValue =>
                          Animated.Value.add(
                            state.animation,
                            Value.interpolate(
                              scrollYAnimatedValue,
                              Interpolation.(
                                config(
                                  ~inputRange=[|(-200.), 1.|],
                                  ~outputRange=
                                    fromFloatArray([|(-200.), 1.|]),
                                  (),
                                )
                              ),
                            ),
                          )
                        )
                      ->Option.getWithDefault(state.animation->Obj.magic),
                    )
                  ),
              ),
            |],
            (),
          )
        )>
        children
      </Animated.View>
    </SafeAreaView>
  </div>;
};
