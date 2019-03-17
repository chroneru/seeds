# seeds

This is R package.
seeds package contains functions which generate object and plot circle, ellipse, parameter representation, and so on.

seeds は、オブジェクトの生成や円、楕円、媒介変数表示のプロットを行う関数をまとめたものです。

# warning

This package is before expanding. so, implementation is not vectorised and not check object's type.

このパッケージは、まだ作ってる最中なので、ベクトル化とオブジェクトのチェックが甘いです。

please use `purrr::map` or `apply` familly.

`purrr::map` や `apply` ファミリーをお使いください。

# dependencies

* tibble
* ggplot2
    * preffix `plot` use tibble and ggplot2.
    * suffix `tibble` use tibble.

* tibble
* ggplot2
    * プレフィックスが `plot` の関数は、tibbleとggplot2
    * サフィックスが `tibble` の関数は、tibble

