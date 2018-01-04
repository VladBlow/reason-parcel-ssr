type asyncMiddleware =
  (Express.Request.t, Express.Response.t, Express.Next.t) => Js.Promise.t(Express.done_);

external asyncMiddlewareFrom : asyncMiddleware => Express.Middleware.t = "%identity";

let app = Express.App.make();

module Status = {
  let make = () =>
    asyncMiddlewareFrom(
      (_req, res, _next) => Express.Response.sendString(res, "works") |> Js.Promise.resolve
    );
};

module App = {
  let make = () =>
    asyncMiddlewareFrom(
      (req, res, _next) => {
        let universalRouter = UniversalRouter.serverRouter(Routes.handlers());
        universalRouter
        |> UniversalRouter.resolve({"pathname": Express.Request.path(req)})
        |> Js.Promise.then_(
             (component) => {
               let html = ReactDOMServerRe.renderToString(<App> component </App>);
               let helmet = ReactHelmet.renderStatic();
               let helmetHtmlAttributes = helmet##htmlAttributes##toString();
               let helmetTitle = helmet##title##toString();
               let helmetMeta = helmet##meta##toString();
               let helmetLink = helmet##link##toString();
               let helmetScript = helmet##script##toString();
               let filePath = Node_path.resolve("./dist", "index.html");
               let index = Node.Fs.readFileAsUtf8Sync(filePath);
               let document =
                 index
                 |> Js.String.replace({j|<html>|j}, {j|<html ⚡ $(helmetHtmlAttributes)>|j})
                 |> Js.String.replace(
                      {j|<head>|j},
                      {j|<head>
                        $helmetTitle
                        $helmetMeta
                        $helmetLink
                        $helmetScript
                    |j}
                    )
                 |> Js.String.replace({j|<div id="root">|j}, {j|<div id="root">$html|j});
               Js.log(Express.Request.path(req));
               let render = () => Express.Response.sendString(res, document);
               render() |> Js.Promise.resolve
             }
           )
      }
    );
};