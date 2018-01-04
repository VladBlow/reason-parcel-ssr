open UniversalRouter;

let handlers = () => [|
  route(~path="", ~action=() => <Home />, ()),
  route(~path="/about", ~action=() => <About />, ())
|];