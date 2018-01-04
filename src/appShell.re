[@bs.val] [@bs.module "react-dom"] external hydrate : (ReasonReact.reactElement, 'a) => unit =
  "hydrate";

type renderElement = ReasonReact.reactElement => ReasonReact.reactElement;

let rootId = Utils.getElementById(Utils.dom, "root");

let render = (location, router) =>
  router
  |> UniversalRouter.resolve({"pathname": location##pathname})
  |> Js.Promise.then_(
       (component: ReasonReact.reactElement) => {
         Js.log("Rendering route : " ++ location##pathname);
         Utils.isPROD ?
           hydrate(<App> component </App>, rootId) :
           ReactDOMRe.renderToElementWithId(<App> component </App>, "root");
         Js.Promise.resolve()
       }
     );

let bootstrap = () => {
  let history = History.createBrowserHistory();
  let dispatcher = (target, event) => {
    Js.log("Redirect to " ++ target);
    ReactEventRe.Mouse.preventDefault(event);
    history##push(target)
  };
  let router = UniversalRouter.clientRouter(Routes.handlers());
  render(history##location, router) |> ignore;
  router
};