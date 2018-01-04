let component = ReasonReact.statelessComponent("Link");

let handleClick = (target, event, _self) => {
  Js.log("Redirect to " ++ target);
  let history = History.createBrowserHistory();
  ReactEventRe.Mouse.preventDefault(event);
  history##push(target)
};

let make = (~_to, ~name, _children) => {
  ...component,
  render: (self) => <a href=_to onClick=(self.handle(handleClick(_to)))> (Utils.text(name)) </a>
};