<?xml version='1.0' encoding='UTF-8' standalone='yes' ?>
<tagfile doxygen_version="1.16.1" doxygen_gitid="669aeeefca743c148e2d935b3d3c69535c7491e6">
  <compound kind="struct">
    <name>kumi::function::adjacent_unicity_t</name>
    <filename>structkumi_1_1function_1_1adjacent__unicity__t.html</filename>
  </compound>
  <compound kind="struct">
    <name>kumi::result::all_unique</name>
    <filename>structkumi_1_1result_1_1all__unique.html</filename>
    <templarg>kumi::concepts::product_type T</templarg>
  </compound>
  <compound kind="struct">
    <name>kumi::all_unique_names</name>
    <filename>structkumi_1_1all__unique__names.html</filename>
    <templarg>typename Ints</templarg>
    <templarg>typename... Ts</templarg>
  </compound>
  <compound kind="struct">
    <name>kumi::all_uniques</name>
    <filename>structkumi_1_1all__uniques.html</filename>
    <templarg>typename Ints</templarg>
    <templarg>typename... Ts</templarg>
  </compound>
  <compound kind="struct">
    <name>kumi::result::apply</name>
    <filename>structkumi_1_1result_1_1apply.html</filename>
    <templarg>typename Function</templarg>
    <templarg>kumi::concepts::product_type T</templarg>
  </compound>
  <compound kind="struct">
    <name>kumi::result::apply_field</name>
    <filename>structkumi_1_1result_1_1apply__field.html</filename>
    <templarg>typename Function</templarg>
    <templarg>kumi::concepts::record_type R</templarg>
  </compound>
  <compound kind="struct">
    <name>kumi::apply_traits</name>
    <filename>structkumi_1_1apply__traits.html</filename>
    <templarg>template&lt; typename... &gt; typename Traits</templarg>
    <templarg>typename T</templarg>
    <templarg>typename Seq</templarg>
  </compound>
  <compound kind="class">
    <name>kumi::as</name>
    <filename>structkumi_1_1as.html</filename>
    <templarg>typename T</templarg>
    <member kind="typedef">
      <type>T</type>
      <name>type</name>
      <anchorfile>structkumi_1_1as.html</anchorfile>
      <anchor>ae0ed33d79b1955359c95eb5e572f7305</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>kumi::result::as_flat_ptr</name>
    <filename>structkumi_1_1result_1_1as__flat__ptr.html</filename>
    <templarg>kumi::concepts::product_type T</templarg>
  </compound>
  <compound kind="struct">
    <name>kumi::as_tuple</name>
    <filename>structkumi_1_1as__tuple.html</filename>
    <templarg>typename T</templarg>
    <templarg>template&lt; typename... &gt; class Meta</templarg>
  </compound>
  <compound kind="struct">
    <name>kumi::result::back</name>
    <filename>structkumi_1_1result_1_1back.html</filename>
    <templarg>kumi::concepts::product_type T</templarg>
    <base>kumi::stored_member&lt; kumi::size_v&lt; T &gt; - 1, T &gt;</base>
  </compound>
  <compound kind="class">
    <name>kumi::function::boolean_and</name>
    <filename>structkumi_1_1function_1_1boolean__and.html</filename>
    <member kind="variable" static="yes">
      <type>static constexpr bool</type>
      <name>identity</name>
      <anchorfile>structkumi_1_1function_1_1boolean__and.html</anchorfile>
      <anchor>ab76cd8c8f2059169433f16b45d02eecd</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>kumi::function::boolean_or</name>
    <filename>structkumi_1_1function_1_1boolean__or.html</filename>
    <member kind="variable" static="yes">
      <type>static constexpr bool</type>
      <name>identity</name>
      <anchorfile>structkumi_1_1function_1_1boolean__or.html</anchorfile>
      <anchor>a2f7848820b2e45a83aa776a11a4617c7</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>kumi::function::boolean_xor</name>
    <filename>structkumi_1_1function_1_1boolean__xor.html</filename>
    <member kind="variable" static="yes">
      <type>static constexpr bool</type>
      <name>identity</name>
      <anchorfile>structkumi_1_1function_1_1boolean__xor.html</anchorfile>
      <anchor>ae232a2d43a04338bb65254cbc736dbea</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>kumi::builder</name>
    <filename>structkumi_1_1builder.html</filename>
    <templarg>typename T</templarg>
  </compound>
  <compound kind="struct">
    <name>kumi::result::cartesian_product</name>
    <filename>structkumi_1_1result_1_1cartesian__product.html</filename>
    <templarg>typename... Ts</templarg>
  </compound>
  <compound kind="struct">
    <name>kumi::result::cat</name>
    <filename>structkumi_1_1result_1_1cat.html</filename>
    <templarg>kumi::concepts::product_type... Ts</templarg>
  </compound>
  <compound kind="struct">
    <name>kumi::result::chunks</name>
    <filename>structkumi_1_1result_1_1chunks.html</filename>
    <templarg>std::size_t N</templarg>
    <templarg>kumi::concepts::product_type T</templarg>
  </compound>
  <compound kind="struct">
    <name>kumi::common_product_type</name>
    <filename>structkumi_1_1common__product__type.html</filename>
    <templarg>typename... Ts</templarg>
  </compound>
  <compound kind="struct">
    <name>kumi::result::compress</name>
    <filename>structkumi_1_1result_1_1compress.html</filename>
    <templarg>kumi::concepts::product_type T</templarg>
  </compound>
  <compound kind="struct">
    <name>kumi::container_size</name>
    <filename>structkumi_1_1container__size.html</filename>
    <templarg>typename T</templarg>
  </compound>
  <compound kind="struct">
    <name>kumi::container_type</name>
    <filename>structkumi_1_1container__type.html</filename>
    <templarg>typename T</templarg>
    <base>kumi::is_container&lt; std::remove_cvref_t&lt; T &gt; &gt;</base>
  </compound>
  <compound kind="struct">
    <name>kumi::result::contains</name>
    <filename>structkumi_1_1result_1_1contains.html</filename>
    <templarg>kumi::concepts::product_type T</templarg>
    <templarg>kumi::concepts::identifier ID</templarg>
  </compound>
  <compound kind="struct">
    <name>kumi::result::contains_any</name>
    <filename>structkumi_1_1result_1_1contains__any.html</filename>
    <templarg>kumi::concepts::product_type T</templarg>
    <templarg>kumi::concepts::identifier... IDs</templarg>
  </compound>
  <compound kind="struct">
    <name>kumi::result::contains_none</name>
    <filename>structkumi_1_1result_1_1contains__none.html</filename>
    <templarg>kumi::concepts::product_type T</templarg>
    <templarg>kumi::concepts::identifier... IDs</templarg>
  </compound>
  <compound kind="struct">
    <name>kumi::result::contains_only</name>
    <filename>structkumi_1_1result_1_1contains__only.html</filename>
    <templarg>kumi::concepts::product_type T</templarg>
    <templarg>kumi::concepts::identifier... IDs</templarg>
  </compound>
  <compound kind="struct">
    <name>kumi::element</name>
    <filename>structkumi_1_1element.html</filename>
    <templarg>std::size_t I</templarg>
    <templarg>typename T</templarg>
  </compound>
  <compound kind="struct">
    <name>kumi::function::element_or</name>
    <filename>structkumi_1_1function_1_1element__or.html</filename>
    <templarg>std::size_t I</templarg>
    <templarg>typename T</templarg>
    <templarg>typename U</templarg>
  </compound>
  <compound kind="struct">
    <name>kumi::result::exclusive_scan_left</name>
    <filename>structkumi_1_1result_1_1exclusive__scan__left.html</filename>
    <templarg>typename Function</templarg>
    <templarg>kumi::concepts::product_type T</templarg>
    <templarg>typename Value</templarg>
  </compound>
  <compound kind="struct">
    <name>kumi::result::exclusive_scan_right</name>
    <filename>structkumi_1_1result_1_1exclusive__scan__right.html</filename>
    <templarg>typename Function</templarg>
    <templarg>kumi::concepts::product_type T</templarg>
    <templarg>typename Value</templarg>
  </compound>
  <compound kind="struct">
    <name>kumi::result::extract</name>
    <filename>structkumi_1_1result_1_1extract.html</filename>
    <templarg>kumi::concepts::product_type T</templarg>
    <templarg>std::size_t I0</templarg>
    <templarg>std::size_t I1</templarg>
  </compound>
  <compound kind="class">
    <name>kumi::field</name>
    <filename>structkumi_1_1field.html</filename>
    <templarg>typename Id</templarg>
    <templarg>typename T</templarg>
    <member kind="function" static="yes">
      <type>static constexpr auto</type>
      <name>label</name>
      <anchorfile>structkumi_1_1field.html</anchorfile>
      <anchor>acd309440c1fca78c1a64750e7a5482df</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>capture_field</name>
      <anchorfile>group__utility_gafc8e80ba53336a0142f3267959c1ba71.html</anchorfile>
      <anchor>gafc8e80ba53336a0142f3267959c1ba71</anchor>
      <arglist>(T &amp;&amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>field_cast</name>
      <anchorfile>group__utility_ga59477c1d8542af2601f493e3320434ee.html</anchorfile>
      <anchor>ga59477c1d8542af2601f493e3320434ee</anchor>
      <arglist>(T &amp;&amp;t) noexcept</arglist>
    </member>
    <member kind="friend">
      <type>friend std::basic_ostream&lt; CharT, Traits &gt; &amp;</type>
      <name>operator&lt;&lt;</name>
      <anchorfile>group__utility.html</anchorfile>
      <anchor>ga34969da06ac58348bc220ebf522233f1</anchor>
      <arglist>(std::basic_ostream&lt; CharT, Traits &gt; &amp;os, field const &amp;w) noexcept</arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>kumi::field&lt; Id, T &gt;</name>
    <filename>structkumi_1_1field_3_01Id_00_01T_01_4.html</filename>
    <templarg>typename Id</templarg>
    <templarg>typename T</templarg>
    <member kind="function" static="yes">
      <type>static constexpr auto</type>
      <name>label</name>
      <anchorfile>structkumi_1_1field_3_01Id_00_01T_01_4.html</anchorfile>
      <anchor>acd309440c1fca78c1a64750e7a5482df</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>capture_field</name>
      <anchorfile>group__utility_gafc8e80ba53336a0142f3267959c1ba71.html</anchorfile>
      <anchor>gafc8e80ba53336a0142f3267959c1ba71</anchor>
      <arglist>(T &amp;&amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>field_cast</name>
      <anchorfile>group__utility_ga59477c1d8542af2601f493e3320434ee.html</anchorfile>
      <anchor>ga59477c1d8542af2601f493e3320434ee</anchor>
      <arglist>(T &amp;&amp;t) noexcept</arglist>
    </member>
    <member kind="friend">
      <type>friend std::basic_ostream&lt; CharT, Traits &gt; &amp;</type>
      <name>operator&lt;&lt;</name>
      <anchorfile>group__utility.html</anchorfile>
      <anchor>ga34969da06ac58348bc220ebf522233f1</anchor>
      <arglist>(std::basic_ostream&lt; CharT, Traits &gt; &amp;os, field const &amp;w) noexcept</arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>kumi::result::fill</name>
    <filename>structkumi_1_1result_1_1fill.html</filename>
    <templarg>std::size_t N</templarg>
    <templarg>typename T</templarg>
  </compound>
  <compound kind="struct">
    <name>kumi::result::filter</name>
    <filename>structkumi_1_1result_1_1filter.html</filename>
    <templarg>template&lt; typename &gt; typename Pred</templarg>
    <templarg>kumi::concepts::product_type T</templarg>
  </compound>
  <compound kind="struct">
    <name>kumi::result::filter_not</name>
    <filename>structkumi_1_1result_1_1filter__not.html</filename>
    <templarg>template&lt; typename &gt; typename Pred</templarg>
    <templarg>kumi::concepts::product_type T</templarg>
  </compound>
  <compound kind="struct">
    <name>kumi::result::flatten</name>
    <filename>structkumi_1_1result_1_1flatten.html</filename>
    <templarg>kumi::concepts::product_type T</templarg>
  </compound>
  <compound kind="struct">
    <name>kumi::result::flatten_all</name>
    <filename>structkumi_1_1result_1_1flatten__all.html</filename>
    <templarg>kumi::concepts::product_type T</templarg>
    <templarg>typename Func</templarg>
  </compound>
  <compound kind="struct">
    <name>kumi::result::fold_left</name>
    <filename>structkumi_1_1result_1_1fold__left.html</filename>
    <templarg>typename Function</templarg>
    <templarg>kumi::concepts::product_type T</templarg>
    <templarg>typename Value</templarg>
  </compound>
  <compound kind="struct">
    <name>kumi::result::fold_right</name>
    <filename>structkumi_1_1result_1_1fold__right.html</filename>
    <templarg>typename Function</templarg>
    <templarg>kumi::concepts::product_type T</templarg>
    <templarg>typename Value</templarg>
  </compound>
  <compound kind="class">
    <name>kumi::function::foldable</name>
    <filename>structkumi_1_1function_1_1foldable.html</filename>
    <templarg>typename T</templarg>
    <member kind="function">
      <type>constexpr auto</type>
      <name>operator()</name>
      <anchorfile>structkumi_1_1function_1_1foldable_a058a4a0c3293567b0aab034517c2306b.html</anchorfile>
      <anchor>a058a4a0c3293567b0aab034517c2306b</anchor>
      <arglist>() const noexcept</arglist>
    </member>
    <member kind="friend">
      <type>friend constexpr decltype(auto)</type>
      <name>operator&lt;&lt;</name>
      <anchorfile>structkumi_1_1function_1_1foldable_a41ffcb368da710bf05ba193e84a3992a.html</anchorfile>
      <anchor>a41ffcb368da710bf05ba193e84a3992a</anchor>
      <arglist>(C &amp;&amp;c, foldable &amp;&amp;f)</arglist>
    </member>
    <member kind="friend">
      <type>friend constexpr decltype(auto)</type>
      <name>operator&gt;&gt;</name>
      <anchorfile>structkumi_1_1function_1_1foldable_a6274172de9a7b4e6c94875ca3401dc5b.html</anchorfile>
      <anchor>a6274172de9a7b4e6c94875ca3401dc5b</anchor>
      <arglist>(foldable &amp;&amp;f, C &amp;&amp;c)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>foldable</name>
      <anchorfile>structkumi_1_1function_1_1foldable_afcef35f6193e023d1434f2b7d45bfd1c.html</anchorfile>
      <anchor>afcef35f6193e023d1434f2b7d45bfd1c</anchor>
      <arglist>(T &amp;&amp;t) -&gt; foldable&lt; std::unwrap_ref_decay_t&lt; T &gt; &gt;</arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>kumi::result::front</name>
    <filename>structkumi_1_1result_1_1front.html</filename>
    <templarg>kumi::concepts::product_type T</templarg>
    <base>kumi::stored_member&lt; 0, T &gt;</base>
  </compound>
  <compound kind="struct">
    <name>kumi::result::generate</name>
    <filename>structkumi_1_1result_1_1generate.html</filename>
    <templarg>std::size_t N</templarg>
    <templarg>typename Function</templarg>
  </compound>
  <compound kind="struct">
    <name>kumi::has_static_size</name>
    <filename>structkumi_1_1has__static__size.html</filename>
    <templarg>typename T</templarg>
  </compound>
  <compound kind="class">
    <name>kumi::identifier</name>
    <filename>structkumi_1_1identifier.html</filename>
    <templarg>typename ID</templarg>
    <templarg>typename Checker</templarg>
    <member kind="typedef">
      <type>identifier&lt; ID, Checker &gt;</type>
      <name>type</name>
      <anchorfile>structkumi_1_1identifier.html</anchorfile>
      <anchor>aae1d9bcd971d43f8831ba98f5d7e2678</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type>constexpr</type>
      <name>identifier</name>
      <anchorfile>structkumi_1_1identifier.html</anchorfile>
      <anchor>a1cbb7d1e8b6adafe05c6b3f43c94db5d</anchor>
      <arglist>() noexcept=default</arglist>
    </member>
    <member kind="function">
      <type>constexpr</type>
      <name>identifier</name>
      <anchorfile>structkumi_1_1identifier_a3b9a31cc021cee475c3dd820c966a104.html</anchorfile>
      <anchor>a3b9a31cc021cee475c3dd820c966a104</anchor>
      <arglist>(ID const &amp;id, Checker const &amp;check) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>operator=</name>
      <anchorfile>structkumi_1_1identifier_afd233fd13ed5f9c794f0c2bb02db1429.html</anchorfile>
      <anchor>afd233fd13ed5f9c794f0c2bb02db1429</anchor>
      <arglist>(T &amp;&amp;v) const noexcept -&gt; kumi::field&lt; type, std::unwrap_ref_decay_t&lt; T &gt; &gt;</arglist>
    </member>
    <member kind="friend">
      <type>friend constexpr kumi::str</type>
      <name>to_str</name>
      <anchorfile>structkumi_1_1identifier.html</anchorfile>
      <anchor>aed98a76222e0731147ce97426434c041</anchor>
      <arglist>(identifier const &amp;)</arglist>
    </member>
    <member kind="friend">
      <type>friend std::basic_ostream&lt; CharT, Traits &gt; &amp;</type>
      <name>operator&lt;&lt;</name>
      <anchorfile>structkumi_1_1identifier.html</anchorfile>
      <anchor>a4042551a86fea06c6d4be2daec274a35</anchor>
      <arglist>(std::basic_ostream&lt; CharT, Traits &gt; &amp;os, identifier const &amp;) noexcept</arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>kumi::result::inclusive_scan_left</name>
    <filename>structkumi_1_1result_1_1inclusive__scan__left.html</filename>
    <templarg>typename Function</templarg>
    <templarg>kumi::concepts::product_type T</templarg>
    <templarg>typename Value</templarg>
  </compound>
  <compound kind="struct">
    <name>kumi::result::inclusive_scan_right</name>
    <filename>structkumi_1_1result_1_1inclusive__scan__right.html</filename>
    <templarg>typename Function</templarg>
    <templarg>kumi::concepts::product_type T</templarg>
    <templarg>typename Value</templarg>
  </compound>
  <compound kind="class">
    <name>kumi::index_t</name>
    <filename>structkumi_1_1index__t.html</filename>
    <templarg>std::size_t N</templarg>
    <member kind="function">
      <type>constexpr</type>
      <name>operator std::integral_constant&lt; std::size_t, N &gt;</name>
      <anchorfile>structkumi_1_1index__t.html</anchorfile>
      <anchor>ad9eadb46e256efabde1b1b55a90533d7</anchor>
      <arglist>() const noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr</type>
      <name>operator std::size_t</name>
      <anchorfile>structkumi_1_1index__t.html</anchorfile>
      <anchor>a4dd6abb0a1663aa1f355ee416ee3083e</anchor>
      <arglist>() const noexcept</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static constexpr auto</type>
      <name>value</name>
      <anchorfile>structkumi_1_1index__t.html</anchorfile>
      <anchor>ab659f5d62c79ae49fe525448df86765b</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>kumi::result::inner_product</name>
    <filename>structkumi_1_1result_1_1inner__product.html</filename>
    <templarg>kumi::concepts::product_type S1</templarg>
    <templarg>kumi::concepts::sized_product_type&lt; kumi::size_v&lt; S1 &gt; &gt; S2</templarg>
    <templarg>typename T</templarg>
    <templarg>typename Sum</templarg>
    <templarg>typename Prod</templarg>
  </compound>
  <compound kind="struct">
    <name>kumi::result::iota</name>
    <filename>structkumi_1_1result_1_1iota.html</filename>
    <templarg>std::size_t N</templarg>
    <templarg>typename T</templarg>
  </compound>
  <compound kind="struct">
    <name>kumi::is_container</name>
    <filename>structkumi_1_1is__container.html</filename>
    <templarg>typename T</templarg>
  </compound>
  <compound kind="struct">
    <name>kumi::is_equality_comparable</name>
    <filename>structkumi_1_1is__equality__comparable.html</filename>
    <templarg>typename Seq</templarg>
    <templarg>typename T</templarg>
    <templarg>typename U</templarg>
  </compound>
  <compound kind="struct">
    <name>kumi::is_equivalent</name>
    <filename>structkumi_1_1is__equivalent.html</filename>
    <templarg>typename Seq</templarg>
    <templarg>typename T</templarg>
    <templarg>typename U</templarg>
  </compound>
  <compound kind="struct">
    <name>kumi::is_homogeneous</name>
    <filename>structkumi_1_1is__homogeneous.html</filename>
    <templarg>typename T</templarg>
  </compound>
  <compound kind="struct">
    <name>kumi::is_product_type</name>
    <filename>structkumi_1_1is__product__type.html</filename>
    <templarg>typename T</templarg>
  </compound>
  <compound kind="struct">
    <name>kumi::is_projection_map</name>
    <filename>structkumi_1_1is__projection__map.html</filename>
    <templarg>typename T</templarg>
  </compound>
  <compound kind="struct">
    <name>kumi::is_record_type</name>
    <filename>structkumi_1_1is__record__type.html</filename>
    <templarg>typename T</templarg>
    <templarg>typename Enable</templarg>
  </compound>
  <compound kind="class">
    <name>kumi::label_t</name>
    <filename>structkumi_1_1label__t.html</filename>
    <templarg>kumi::str Label</templarg>
    <member kind="function">
      <type>constexpr</type>
      <name>operator kumi::str</name>
      <anchorfile>structkumi_1_1label__t.html</anchorfile>
      <anchor>ae04311b56f486908576c12a8ef8e9923</anchor>
      <arglist>() const noexcept</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static constexpr kumi::str</type>
      <name>value</name>
      <anchorfile>structkumi_1_1label__t.html</anchorfile>
      <anchor>a872221f3e54f331778f4971e6e7407ed</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>kumi::result::map</name>
    <filename>structkumi_1_1result_1_1map.html</filename>
    <templarg>typename Function</templarg>
    <templarg>kumi::concepts::product_type T</templarg>
    <templarg>kumi::concepts::sized_product_type&lt; kumi::size_v&lt; T &gt; &gt;... Ts</templarg>
  </compound>
  <compound kind="struct">
    <name>kumi::result::map_field</name>
    <filename>structkumi_1_1result_1_1map__field.html</filename>
    <templarg>typename Function</templarg>
    <templarg>kumi::concepts::record_type T</templarg>
    <templarg>kumi::concepts::sized_product_type&lt; kumi::size_v&lt; T &gt; &gt;... Ts</templarg>
  </compound>
  <compound kind="struct">
    <name>kumi::result::map_index</name>
    <filename>structkumi_1_1result_1_1map__index.html</filename>
    <templarg>typename Function</templarg>
    <templarg>kumi::concepts::product_type T</templarg>
    <templarg>kumi::concepts::sized_product_type&lt; kumi::size_v&lt; T &gt; &gt;... Ts</templarg>
  </compound>
  <compound kind="struct">
    <name>kumi::map_traits</name>
    <filename>structkumi_1_1map__traits.html</filename>
    <templarg>template&lt; typename... &gt; typename Traits</templarg>
    <templarg>typename T</templarg>
    <templarg>typename Seq</templarg>
  </compound>
  <compound kind="struct">
    <name>kumi::result::max</name>
    <filename>structkumi_1_1result_1_1max.html</filename>
    <templarg>typename T</templarg>
    <templarg>typename F</templarg>
  </compound>
  <compound kind="struct">
    <name>kumi::result::max_flat</name>
    <filename>structkumi_1_1result_1_1max__flat.html</filename>
    <templarg>typename T</templarg>
    <templarg>typename F</templarg>
  </compound>
  <compound kind="struct">
    <name>kumi::member</name>
    <filename>structkumi_1_1member.html</filename>
    <templarg>std::size_t I</templarg>
    <templarg>typename T</templarg>
  </compound>
  <compound kind="struct">
    <name>kumi::result::member_cast</name>
    <filename>structkumi_1_1result_1_1member__cast.html</filename>
    <templarg>typename Target</templarg>
    <templarg>kumi::concepts::product_type T</templarg>
  </compound>
  <compound kind="struct">
    <name>kumi::result::min</name>
    <filename>structkumi_1_1result_1_1min.html</filename>
    <templarg>typename T</templarg>
    <templarg>typename F</templarg>
  </compound>
  <compound kind="struct">
    <name>kumi::result::min_flat</name>
    <filename>structkumi_1_1result_1_1min__flat.html</filename>
    <templarg>typename T</templarg>
    <templarg>typename F</templarg>
  </compound>
  <compound kind="class">
    <name>kumi::name</name>
    <filename>structkumi_1_1name.html</filename>
    <templarg>kumi::str ID</templarg>
    <member kind="typedef">
      <type>name&lt; ID &gt;</type>
      <name>type</name>
      <anchorfile>structkumi_1_1name.html</anchorfile>
      <anchor>a9bf8b825d5ec4deb4d1cb8b5c23f773f</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>operator=</name>
      <anchorfile>structkumi_1_1name_a7f497fc96b78d370ec817a1706041743.html</anchorfile>
      <anchor>a7f497fc96b78d370ec817a1706041743</anchor>
      <arglist>(T &amp;&amp;v) const noexcept -&gt; kumi::field&lt; type, std::unwrap_ref_decay_t&lt; T &gt; &gt;</arglist>
    </member>
    <member kind="friend">
      <type>friend constexpr kumi::str</type>
      <name>to_str</name>
      <anchorfile>structkumi_1_1name.html</anchorfile>
      <anchor>a35dd8f2c52e6c42d8d1ba3529e7e4668</anchor>
      <arglist>(name const &amp;)</arglist>
    </member>
    <member kind="friend">
      <type>friend std::basic_ostream&lt; CharT, Traits &gt; &amp;</type>
      <name>operator&lt;&lt;</name>
      <anchorfile>structkumi_1_1name.html</anchorfile>
      <anchor>a7581a84b154ddc4d1741eff4890d720a</anchor>
      <arglist>(std::basic_ostream&lt; CharT, Traits &gt; &amp;os, name const &amp;) noexcept</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>kumi::function::numeric_add</name>
    <filename>structkumi_1_1function_1_1numeric__add.html</filename>
    <member kind="variable" static="yes">
      <type>static constexpr auto</type>
      <name>identity</name>
      <anchorfile>structkumi_1_1function_1_1numeric__add.html</anchorfile>
      <anchor>aa873c7638061899a652e97fdf45e1452</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>kumi::function::numeric_prod</name>
    <filename>structkumi_1_1function_1_1numeric__prod.html</filename>
    <member kind="variable" static="yes">
      <type>static constexpr auto</type>
      <name>identity</name>
      <anchorfile>structkumi_1_1function_1_1numeric__prod.html</anchorfile>
      <anchor>a442630c534784c7794c0ced4bbaafcda</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>kumi::result::partition</name>
    <filename>structkumi_1_1result_1_1partition.html</filename>
    <templarg>template&lt; typename &gt; typename Pred</templarg>
    <templarg>kumi::concepts::product_type T</templarg>
  </compound>
  <compound kind="struct">
    <name>kumi::result::pop_back</name>
    <filename>structkumi_1_1result_1_1pop__back.html</filename>
    <templarg>kumi::concepts::product_type T</templarg>
  </compound>
  <compound kind="struct">
    <name>kumi::result::pop_front</name>
    <filename>structkumi_1_1result_1_1pop__front.html</filename>
    <templarg>kumi::concepts::product_type T</templarg>
  </compound>
  <compound kind="class">
    <name>kumi::projection_map</name>
    <filename>structkumi_1_1projection__map.html</filename>
    <templarg>auto... V</templarg>
    <member kind="friend">
      <type>friend constexpr decltype(auto)</type>
      <name>get</name>
      <anchorfile>structkumi_1_1projection__map_a197ce3f55a71294cb619b65ba8d8cc89.html</anchorfile>
      <anchor>a197ce3f55a71294cb619b65ba8d8cc89</anchor>
      <arglist>(projection_map const &amp;pm) noexcept</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static constexpr auto</type>
      <name>size</name>
      <anchorfile>structkumi_1_1projection__map.html</anchorfile>
      <anchor>aa201fda6e2720aef8e4a7ce8baee802e</anchor>
      <arglist>() noexcept</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static constexpr auto</type>
      <name>empty</name>
      <anchorfile>structkumi_1_1projection__map.html</anchorfile>
      <anchor>a09b37b6512103836987e98b7c0d75984</anchor>
      <arglist>() noexcept</arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>kumi::result::push_back</name>
    <filename>structkumi_1_1result_1_1push__back.html</filename>
    <templarg>kumi::concepts::product_type T</templarg>
    <templarg>typename V</templarg>
  </compound>
  <compound kind="struct">
    <name>kumi::result::push_front</name>
    <filename>structkumi_1_1result_1_1push__front.html</filename>
    <templarg>kumi::concepts::product_type T</templarg>
    <templarg>typename V</templarg>
  </compound>
  <compound kind="class">
    <name>kumi::record</name>
    <filename>structkumi_1_1record.html</filename>
    <templarg>typename... Ts</templarg>
    <member kind="function">
      <type>constexpr record &amp;</type>
      <name>operator=</name>
      <anchorfile>structkumi_1_1record.html</anchorfile>
      <anchor>a396775fba3713955c4992e7e37fe0f0f</anchor>
      <arglist>(record&lt; Us... &gt; &amp;&amp;other)</arglist>
    </member>
    <member kind="function">
      <type>constexpr record &amp;</type>
      <name>operator=</name>
      <anchorfile>structkumi_1_1record_a82f8b6d7908e60f4829467f6a8c12384.html</anchorfile>
      <anchor>a82f8b6d7908e60f4829467f6a8c12384</anchor>
      <arglist>(record&lt; Us... &gt; const &amp;other)</arglist>
    </member>
    <member kind="friend">
      <type>friend std::basic_ostream&lt; CharT, Traits &gt; &amp;</type>
      <name>operator&lt;&lt;</name>
      <anchorfile>structkumi_1_1record.html</anchorfile>
      <anchor>a3e776cea74b6cbba98d32566764b3571</anchor>
      <arglist>(std::basic_ostream&lt; CharT, Traits &gt; &amp;os, record const &amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1record_afe22fa7b24c2c6257671ce28a566cce7.html</anchorfile>
      <anchor>afe22fa7b24c2c6257671ce28a566cce7</anchor>
      <arglist>(kumi::index_t&lt; I &gt; i) &amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1record.html</anchorfile>
      <anchor>a0982b5466f4f0943a5bf42f1a0aff576</anchor>
      <arglist>(kumi::index_t&lt; I &gt;) &amp;&amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1record.html</anchorfile>
      <anchor>ac725adbeb4b65f91058d3bfc91d66335</anchor>
      <arglist>(kumi::index_t&lt; I &gt;) const &amp;&amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1record.html</anchorfile>
      <anchor>ae7963719866868799e0ee02626b83d67</anchor>
      <arglist>(kumi::index_t&lt; I &gt;) const &amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1record_a8d69c24669ea60edfb2253967a09009a.html</anchorfile>
      <anchor>a8d69c24669ea60edfb2253967a09009a</anchor>
      <arglist>(kumi::as&lt; T &gt; type) &amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1record.html</anchorfile>
      <anchor>a5cd42a9117ea19ce0a3ed103b1f69b5a</anchor>
      <arglist>(kumi::as&lt; T &gt;) &amp;&amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1record.html</anchorfile>
      <anchor>a3a5d33e3f8ec9566ed099bd27ff01c96</anchor>
      <arglist>(kumi::as&lt; T &gt;) const &amp;&amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1record.html</anchorfile>
      <anchor>a247bf105ce5d9529452216eb27342779</anchor>
      <arglist>(kumi::as&lt; T &gt;) const &amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1record_a24420aaaf1ba42d322270296d094fbfa.html</anchorfile>
      <anchor>a24420aaaf1ba42d322270296d094fbfa</anchor>
      <arglist>(kumi::label_t&lt; Name &gt; l) &amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1record.html</anchorfile>
      <anchor>a98043c2c63bf512d114f81d4b0364acb</anchor>
      <arglist>(kumi::label_t&lt; Name &gt;) &amp;&amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1record.html</anchorfile>
      <anchor>a486114f35058ce5b0f34835c474a3c36</anchor>
      <arglist>(kumi::label_t&lt; Name &gt;) const &amp;&amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1record.html</anchorfile>
      <anchor>ac1d95daeb0db9e0733e2e79e65a8c991</anchor>
      <arglist>(kumi::label_t&lt; Name &gt;) const &amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1record_a31c8f07c20352d38c51afd1ca872eec2.html</anchorfile>
      <anchor>a31c8f07c20352d38c51afd1ca872eec2</anchor>
      <arglist>(Id const &amp;) &amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1record.html</anchorfile>
      <anchor>acbfe3f9bd69057c3c7b228b45e8f82c4</anchor>
      <arglist>(Id const &amp;) &amp;&amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1record.html</anchorfile>
      <anchor>aab158fc3470145a9215e6bb80474f0a4</anchor>
      <arglist>(Id const &amp;) const &amp;&amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1record.html</anchorfile>
      <anchor>a5c9d75f431a2453078baf16553dc9a28</anchor>
      <arglist>(Id const &amp;) const &amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>values</name>
      <anchorfile>structkumi_1_1record.html</anchorfile>
      <anchor>a9b9b96d4aae04575e8c2ff5ab515b594</anchor>
      <arglist>() noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>values</name>
      <anchorfile>structkumi_1_1record.html</anchorfile>
      <anchor>aed4f570ae92586a34d7f03b4bc584ebc</anchor>
      <arglist>() const noexcept</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static constexpr auto</type>
      <name>size</name>
      <anchorfile>structkumi_1_1record_ae58c2eac14a343992ac19d9ba01ec6ae.html</anchorfile>
      <anchor>ae58c2eac14a343992ac19d9ba01ec6ae</anchor>
      <arglist>() noexcept</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static constexpr bool</type>
      <name>empty</name>
      <anchorfile>structkumi_1_1record_a7e54e12c537c8dcbafabc215957f0abc.html</anchorfile>
      <anchor>a7e54e12c537c8dcbafabc215957f0abc</anchor>
      <arglist>() noexcept</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static constexpr auto</type>
      <name>identifiers</name>
      <anchorfile>structkumi_1_1record.html</anchorfile>
      <anchor>ac730d46c3db986909e0c910b74648b4a</anchor>
      <arglist>() noexcept</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static constexpr auto</type>
      <name>labels</name>
      <anchorfile>structkumi_1_1record.html</anchorfile>
      <anchor>a57fe20038a1592ea37e9a8954c013d80</anchor>
      <arglist>() noexcept</arglist>
    </member>
    <member kind="friend">
      <type>friend constexpr auto</type>
      <name>operator==</name>
      <anchorfile>structkumi_1_1record.html</anchorfile>
      <anchor>a6db5145d0e86cffe51b9941346834323</anchor>
      <arglist>(record const &amp;self, record&lt; Us... &gt; const &amp;other) noexcept</arglist>
    </member>
    <member kind="friend">
      <type>friend constexpr auto</type>
      <name>operator!=</name>
      <anchorfile>structkumi_1_1record.html</anchorfile>
      <anchor>a22e02cc7d670843e1c5f9e41385a7237</anchor>
      <arglist>(record const &amp;self, record&lt; Us... &gt; const &amp;other) noexcept</arglist>
    </member>
    <member kind="function">
      <type>KUMI_CUDA</type>
      <name>record</name>
      <anchorfile>structkumi_1_1record_a1000cb0996a9587f8735a35f76060e44.html</anchorfile>
      <anchor>a1000cb0996a9587f8735a35f76060e44</anchor>
      <arglist>(Ts &amp;&amp;...) -&gt; record&lt; std::unwrap_ref_decay_t&lt; Ts &gt;... &gt;</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1record_abc2cd329ad25d155458850c19cc3b137.html</anchorfile>
      <anchor>abc2cd329ad25d155458850c19cc3b137</anchor>
      <arglist>(record&lt; Ts... &gt; &amp;r) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1record_add6a786a9f4cf8a88d85f0b3b88d4705.html</anchorfile>
      <anchor>add6a786a9f4cf8a88d85f0b3b88d4705</anchor>
      <arglist>(record&lt; Ts... &gt; &amp;&amp;r) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1record_a275ab6e86c6128f8f5e2c30ef3f26c4f.html</anchorfile>
      <anchor>a275ab6e86c6128f8f5e2c30ef3f26c4f</anchor>
      <arglist>(record&lt; Ts... &gt; const &amp;r) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1record_a3dc6eb9adc6e77531fe60520794558a5.html</anchorfile>
      <anchor>a3dc6eb9adc6e77531fe60520794558a5</anchor>
      <arglist>(record&lt; Ts... &gt; const &amp;&amp;r) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1record_abc2cd329ad25d155458850c19cc3b137.html</anchorfile>
      <anchor>abc2cd329ad25d155458850c19cc3b137</anchor>
      <arglist>(record&lt; Ts... &gt; &amp;r) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1record_add6a786a9f4cf8a88d85f0b3b88d4705.html</anchorfile>
      <anchor>add6a786a9f4cf8a88d85f0b3b88d4705</anchor>
      <arglist>(record&lt; Ts... &gt; &amp;&amp;r) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1record_a275ab6e86c6128f8f5e2c30ef3f26c4f.html</anchorfile>
      <anchor>a275ab6e86c6128f8f5e2c30ef3f26c4f</anchor>
      <arglist>(record&lt; Ts... &gt; const &amp;r) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1record_a3dc6eb9adc6e77531fe60520794558a5.html</anchorfile>
      <anchor>a3dc6eb9adc6e77531fe60520794558a5</anchor>
      <arglist>(record&lt; Ts... &gt; const &amp;&amp;r) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1record_abc2cd329ad25d155458850c19cc3b137.html</anchorfile>
      <anchor>abc2cd329ad25d155458850c19cc3b137</anchor>
      <arglist>(record&lt; Ts... &gt; &amp;r) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1record_add6a786a9f4cf8a88d85f0b3b88d4705.html</anchorfile>
      <anchor>add6a786a9f4cf8a88d85f0b3b88d4705</anchor>
      <arglist>(record&lt; Ts... &gt; &amp;&amp;r) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1record_a275ab6e86c6128f8f5e2c30ef3f26c4f.html</anchorfile>
      <anchor>a275ab6e86c6128f8f5e2c30ef3f26c4f</anchor>
      <arglist>(record&lt; Ts... &gt; const &amp;r) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1record_a3dc6eb9adc6e77531fe60520794558a5.html</anchorfile>
      <anchor>a3dc6eb9adc6e77531fe60520794558a5</anchor>
      <arglist>(record&lt; Ts... &gt; const &amp;&amp;r) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1record_abc2cd329ad25d155458850c19cc3b137.html</anchorfile>
      <anchor>abc2cd329ad25d155458850c19cc3b137</anchor>
      <arglist>(record&lt; Ts... &gt; &amp;r) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1record_add6a786a9f4cf8a88d85f0b3b88d4705.html</anchorfile>
      <anchor>add6a786a9f4cf8a88d85f0b3b88d4705</anchor>
      <arglist>(record&lt; Ts... &gt; &amp;&amp;r) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1record_a275ab6e86c6128f8f5e2c30ef3f26c4f.html</anchorfile>
      <anchor>a275ab6e86c6128f8f5e2c30ef3f26c4f</anchor>
      <arglist>(record&lt; Ts... &gt; const &amp;r) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1record_a3dc6eb9adc6e77531fe60520794558a5.html</anchorfile>
      <anchor>a3dc6eb9adc6e77531fe60520794558a5</anchor>
      <arglist>(record&lt; Ts... &gt; const &amp;&amp;r) noexcept</arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>kumi::result::reindex</name>
    <filename>structkumi_1_1result_1_1reindex.html</filename>
    <templarg>kumi::concepts::product_type T</templarg>
    <templarg>kumi::concepts::projection_map auto Indexes</templarg>
  </compound>
  <compound kind="struct">
    <name>kumi::result::remove</name>
    <filename>structkumi_1_1result_1_1remove.html</filename>
    <templarg>kumi::concepts::product_type T</templarg>
    <templarg>std::size_t I0</templarg>
    <templarg>std::size_t I1</templarg>
  </compound>
  <compound kind="struct">
    <name>kumi::result::reorder</name>
    <filename>structkumi_1_1result_1_1reorder.html</filename>
    <templarg>kumi::concepts::product_type T</templarg>
    <templarg>std::size_t... Idx</templarg>
  </compound>
  <compound kind="struct">
    <name>kumi::result::reorder_fields</name>
    <filename>structkumi_1_1result_1_1reorder__fields.html</filename>
    <templarg>kumi::concepts::product_type Tuple</templarg>
    <templarg>kumi::concepts::identifier auto... Name</templarg>
  </compound>
  <compound kind="struct">
    <name>kumi::result::reverse</name>
    <filename>structkumi_1_1result_1_1reverse.html</filename>
    <templarg>kumi::concepts::product_type T</templarg>
  </compound>
  <compound kind="struct">
    <name>kumi::result::rotate_left</name>
    <filename>structkumi_1_1result_1_1rotate__left.html</filename>
    <templarg>std::size_t R</templarg>
    <templarg>kumi::concepts::product_type T</templarg>
  </compound>
  <compound kind="struct">
    <name>kumi::result::rotate_right</name>
    <filename>structkumi_1_1result_1_1rotate__right.html</filename>
    <templarg>std::size_t R</templarg>
    <templarg>kumi::concepts::product_type T</templarg>
  </compound>
  <compound kind="class">
    <name>kumi::function::scannable</name>
    <filename>structkumi_1_1function_1_1scannable.html</filename>
    <templarg>typename F</templarg>
    <templarg>typename V</templarg>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator()</name>
      <anchorfile>structkumi_1_1function_1_1scannable_ae2b8d4cb8c7a10c67bc1efd15b375f8d.html</anchorfile>
      <anchor>ae2b8d4cb8c7a10c67bc1efd15b375f8d</anchor>
      <arglist>() const noexcept</arglist>
    </member>
    <member kind="friend">
      <type>friend constexpr decltype(auto)</type>
      <name>operator&lt;&lt;</name>
      <anchorfile>structkumi_1_1function_1_1scannable_a8c1e8999b59c5cda817381bf6ae3a198.html</anchorfile>
      <anchor>a8c1e8999b59c5cda817381bf6ae3a198</anchor>
      <arglist>(C &amp;&amp;c, scannable &amp;&amp;s)</arglist>
    </member>
    <member kind="friend">
      <type>friend constexpr decltype(auto)</type>
      <name>operator&gt;&gt;</name>
      <anchorfile>structkumi_1_1function_1_1scannable_adefe959b56f2d22a08ef8715dfc15cb7.html</anchorfile>
      <anchor>adefe959b56f2d22a08ef8715dfc15cb7</anchor>
      <arglist>(scannable &amp;&amp;s, C &amp;&amp;c)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>scannable</name>
      <anchorfile>structkumi_1_1function_1_1scannable_ac3570f9286b470ae88de5a142941751a.html</anchorfile>
      <anchor>ac3570f9286b470ae88de5a142941751a</anchor>
      <arglist>(F &amp;&amp;f, T &amp;&amp;t) -&gt; scannable&lt; F, std::unwrap_ref_decay_t&lt; T &gt; &gt;</arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>kumi::function::select_t</name>
    <filename>structkumi_1_1function_1_1select__t.html</filename>
  </compound>
  <compound kind="struct">
    <name>kumi::size</name>
    <filename>structkumi_1_1size.html</filename>
    <templarg>typename T</templarg>
  </compound>
  <compound kind="struct">
    <name>kumi::function::size_or</name>
    <filename>structkumi_1_1function_1_1size__or.html</filename>
    <templarg>typename T</templarg>
    <templarg>auto V</templarg>
  </compound>
  <compound kind="struct">
    <name>kumi::result::split</name>
    <filename>structkumi_1_1result_1_1split.html</filename>
    <templarg>kumi::concepts::product_type T</templarg>
    <templarg>std::size_t I0</templarg>
  </compound>
  <compound kind="struct">
    <name>kumi::stored_element</name>
    <filename>structkumi_1_1stored__element.html</filename>
    <templarg>std::size_t I</templarg>
    <templarg>typename T</templarg>
  </compound>
  <compound kind="struct">
    <name>kumi::stored_member</name>
    <filename>structkumi_1_1stored__member.html</filename>
    <templarg>std::size_t I</templarg>
    <templarg>typename T</templarg>
  </compound>
  <compound kind="class">
    <name>kumi::str</name>
    <filename>structkumi_1_1str.html</filename>
  </compound>
  <compound kind="struct">
    <name>kumi::result::tiles</name>
    <filename>structkumi_1_1result_1_1tiles.html</filename>
    <templarg>std::size_t N</templarg>
    <templarg>std::size_t O</templarg>
    <templarg>kumi::concepts::product_type T</templarg>
  </compound>
  <compound kind="struct">
    <name>kumi::result::transpose</name>
    <filename>structkumi_1_1result_1_1transpose.html</filename>
    <templarg>kumi::concepts::product_type T</templarg>
  </compound>
  <compound kind="class">
    <name>kumi::tuple</name>
    <filename>structkumi_1_1tuple.html</filename>
    <templarg>typename... Ts</templarg>
    <member kind="function">
      <type>constexpr tuple &amp;</type>
      <name>operator=</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>a14faa9d3cc7ddc1ded423c7c315f770f</anchor>
      <arglist>(tuple&lt; Us... &gt; &amp;&amp;other)</arglist>
    </member>
    <member kind="function">
      <type>constexpr tuple &amp;</type>
      <name>operator=</name>
      <anchorfile>structkumi_1_1tuple_a2ea9ed2c89c9f857f9ea9e78d3e55415.html</anchorfile>
      <anchor>a2ea9ed2c89c9f857f9ea9e78d3e55415</anchor>
      <arglist>(tuple&lt; Us... &gt; const &amp;other)</arglist>
    </member>
    <member kind="friend">
      <type>friend std::basic_ostream&lt; CharT, Traits &gt; &amp;</type>
      <name>operator&lt;&lt;</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>af6739a069131e315597688e5b3cf5df9</anchor>
      <arglist>(std::basic_ostream&lt; CharT, Traits &gt; &amp;os, tuple const &amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1tuple_a9642386ee7679de26bcc7be48128073d.html</anchorfile>
      <anchor>a9642386ee7679de26bcc7be48128073d</anchor>
      <arglist>(kumi::index_t&lt; I &gt; i) &amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>a9c771ad0b2f04d7bba28a4e3906d915d</anchor>
      <arglist>(kumi::index_t&lt; I &gt;) &amp;&amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>ac387bc56430a45ba5e8d797c61b8ff2d</anchor>
      <arglist>(kumi::index_t&lt; I &gt;) const &amp;&amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>a292267a2b139d90a3238aad166bfcdfa</anchor>
      <arglist>(kumi::index_t&lt; I &gt;) const &amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1tuple_ad7617c6685a224f58e2c6f45df0cb726.html</anchorfile>
      <anchor>ad7617c6685a224f58e2c6f45df0cb726</anchor>
      <arglist>(kumi::as&lt; T &gt; type) &amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>a8c0031b90900565815c006c223c7159c</anchor>
      <arglist>(kumi::as&lt; T &gt;) &amp;&amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>a763f1b3e9b47ae1d6fd213ee7828936a</anchor>
      <arglist>(kumi::as&lt; T &gt;) const &amp;&amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>ab187f8ddffa548d7bc17f39bbbcf4b50</anchor>
      <arglist>(kumi::as&lt; T &gt;) const &amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1tuple_a0bbd24629b0ebd7b833364a72e604a67.html</anchorfile>
      <anchor>a0bbd24629b0ebd7b833364a72e604a67</anchor>
      <arglist>(kumi::label_t&lt; L &gt; s) &amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>ac9f408ae6b7545cce710931bd4fc970b</anchor>
      <arglist>(kumi::label_t&lt; L &gt;) &amp;&amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>ac1b37d5e96ae8c5fa355b9862c79ed0c</anchor>
      <arglist>(kumi::label_t&lt; L &gt;) const &amp;&amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>a361a7552ac0290826eedf4efe15e2859</anchor>
      <arglist>(kumi::label_t&lt; L &gt;) const &amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1tuple_a18682a7418347e139227e26868486eca.html</anchorfile>
      <anchor>a18682a7418347e139227e26868486eca</anchor>
      <arglist>(Id const &amp;) &amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>a891b26a59ea0b5d496f0f96a128f9bd8</anchor>
      <arglist>(Id const &amp;) &amp;&amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>a338981edc5d3aa6e9e5b0ef604bdb298</anchor>
      <arglist>(Id const &amp;) const &amp;&amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>a2535ed124742921f2d9f813adebca1b2</anchor>
      <arglist>(Id const &amp;) const &amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr</type>
      <name>operator tuple&lt; Us... &gt;</name>
      <anchorfile>structkumi_1_1tuple_ad1a538cf24f719ead736cc23e6559c81.html</anchorfile>
      <anchor>ad1a538cf24f719ead736cc23e6559c81</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>constexpr</type>
      <name>operator tuple&lt; Us... &gt;</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>a692f7d015f9c101bb4c0e17cbf1deb77</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static constexpr auto</type>
      <name>size</name>
      <anchorfile>structkumi_1_1tuple_a0d0957e5314d780693c3d67344a42b3e.html</anchorfile>
      <anchor>a0d0957e5314d780693c3d67344a42b3e</anchor>
      <arglist>() noexcept</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static constexpr bool</type>
      <name>empty</name>
      <anchorfile>structkumi_1_1tuple_af1a74e00134be29916bb7fb6e8cda5f6.html</anchorfile>
      <anchor>af1a74e00134be29916bb7fb6e8cda5f6</anchor>
      <arglist>() noexcept</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static constexpr auto</type>
      <name>identifiers</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>a20bf7b884e66f42a41076a4b1535054b</anchor>
      <arglist>() noexcept</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static constexpr auto</type>
      <name>labels</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>afcfee8fbd3a138d70cff1edb3485e61e</anchor>
      <arglist>() noexcept</arglist>
    </member>
    <member kind="friend">
      <type>friend constexpr auto</type>
      <name>operator==</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>af0256993b0ad272335b4c6d77afe73d7</anchor>
      <arglist>(tuple const &amp;self, tuple&lt; Us... &gt; const &amp;other) noexcept</arglist>
    </member>
    <member kind="friend">
      <type>friend constexpr auto</type>
      <name>operator!=</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>a723ee5d6b1324e146a4cb8819c29f331</anchor>
      <arglist>(tuple const &amp;self, tuple&lt; Us... &gt; const &amp;other) noexcept</arglist>
    </member>
    <member kind="friend">
      <type>friend constexpr auto</type>
      <name>operator&lt;</name>
      <anchorfile>structkumi_1_1tuple_abee5ae96fdfd2145347fa3b2b212bf12.html</anchorfile>
      <anchor>abee5ae96fdfd2145347fa3b2b212bf12</anchor>
      <arglist>(tuple const &amp;lhs, tuple&lt; Us... &gt; const &amp;rhs) noexcept</arglist>
    </member>
    <member kind="friend">
      <type>friend constexpr auto</type>
      <name>operator&lt;=</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>a03b20df5887479d4b7277e30302266ea</anchor>
      <arglist>(tuple const &amp;lhs, tuple&lt; Us... &gt; const &amp;rhs) noexcept</arglist>
    </member>
    <member kind="friend">
      <type>friend constexpr auto</type>
      <name>operator&gt;</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>a741431fe551f58d39edd28b6f6d005ae</anchor>
      <arglist>(tuple const &amp;lhs, tuple&lt; Us... &gt; const &amp;rhs) noexcept</arglist>
    </member>
    <member kind="friend">
      <type>friend constexpr auto</type>
      <name>operator&gt;=</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>a6b3f89a6d6b94821ab32117291342a64</anchor>
      <arglist>(tuple const &amp;lhs, tuple&lt; Us... &gt; const &amp;rhs) noexcept</arglist>
    </member>
    <member kind="function">
      <type>KUMI_CUDA</type>
      <name>tuple</name>
      <anchorfile>structkumi_1_1tuple_a889b9718ac16b1be40acc38689401cd1.html</anchorfile>
      <anchor>a889b9718ac16b1be40acc38689401cd1</anchor>
      <arglist>(Ts &amp;&amp;...) -&gt; tuple&lt; std::unwrap_ref_decay_t&lt; Ts &gt;... &gt;</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>members_of</name>
      <anchorfile>structkumi_1_1tuple_ac67c6dbee8bf12133da3379826cde848.html</anchorfile>
      <anchor>ac67c6dbee8bf12133da3379826cde848</anchor>
      <arglist>(as&lt; T &gt;) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>values_of</name>
      <anchorfile>structkumi_1_1tuple_ade5f616b3115a74bd4930f70f96ca199.html</anchorfile>
      <anchor>ade5f616b3115a74bd4930f70f96ca199</anchor>
      <arglist>(T &amp;&amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1tuple_a7b9b1b3fbe3d201542691bee350d8a08.html</anchorfile>
      <anchor>a7b9b1b3fbe3d201542691bee350d8a08</anchor>
      <arglist>(tuple&lt; Ts... &gt; &amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1tuple_a808bbc50bf9ed9681c41b55f5444e9ea.html</anchorfile>
      <anchor>a808bbc50bf9ed9681c41b55f5444e9ea</anchor>
      <arglist>(tuple&lt; Ts... &gt; &amp;&amp;arg) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1tuple_adcfd380d3fc78581e99125f49e32ae0a.html</anchorfile>
      <anchor>adcfd380d3fc78581e99125f49e32ae0a</anchor>
      <arglist>(tuple&lt; Ts... &gt; const &amp;arg) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1tuple_aaea300b4c7c7cbe1103612b28ba470b5.html</anchorfile>
      <anchor>aaea300b4c7c7cbe1103612b28ba470b5</anchor>
      <arglist>(tuple&lt; Ts... &gt; const &amp;&amp;arg) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1tuple_a7b9b1b3fbe3d201542691bee350d8a08.html</anchorfile>
      <anchor>a7b9b1b3fbe3d201542691bee350d8a08</anchor>
      <arglist>(tuple&lt; Ts... &gt; &amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1tuple_a83e0ac15f8a19c27cfa885b662daed27.html</anchorfile>
      <anchor>a83e0ac15f8a19c27cfa885b662daed27</anchor>
      <arglist>(tuple&lt; Ts... &gt; &amp;&amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1tuple_a7a96007c3fe14162df0e69e6dee3ed96.html</anchorfile>
      <anchor>a7a96007c3fe14162df0e69e6dee3ed96</anchor>
      <arglist>(tuple&lt; Ts... &gt; const &amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1tuple_a85bd7598dcbb6464a3a89990b0e64aa4.html</anchorfile>
      <anchor>a85bd7598dcbb6464a3a89990b0e64aa4</anchor>
      <arglist>(tuple&lt; Ts... &gt; const &amp;&amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1tuple_a7b9b1b3fbe3d201542691bee350d8a08.html</anchorfile>
      <anchor>a7b9b1b3fbe3d201542691bee350d8a08</anchor>
      <arglist>(tuple&lt; Ts... &gt; &amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1tuple_a83e0ac15f8a19c27cfa885b662daed27.html</anchorfile>
      <anchor>a83e0ac15f8a19c27cfa885b662daed27</anchor>
      <arglist>(tuple&lt; Ts... &gt; &amp;&amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1tuple_a7a96007c3fe14162df0e69e6dee3ed96.html</anchorfile>
      <anchor>a7a96007c3fe14162df0e69e6dee3ed96</anchor>
      <arglist>(tuple&lt; Ts... &gt; const &amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1tuple_a85bd7598dcbb6464a3a89990b0e64aa4.html</anchorfile>
      <anchor>a85bd7598dcbb6464a3a89990b0e64aa4</anchor>
      <arglist>(tuple&lt; Ts... &gt; const &amp;&amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1tuple_a7b9b1b3fbe3d201542691bee350d8a08.html</anchorfile>
      <anchor>a7b9b1b3fbe3d201542691bee350d8a08</anchor>
      <arglist>(tuple&lt; Ts... &gt; &amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1tuple_a83e0ac15f8a19c27cfa885b662daed27.html</anchorfile>
      <anchor>a83e0ac15f8a19c27cfa885b662daed27</anchor>
      <arglist>(tuple&lt; Ts... &gt; &amp;&amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1tuple_a7a96007c3fe14162df0e69e6dee3ed96.html</anchorfile>
      <anchor>a7a96007c3fe14162df0e69e6dee3ed96</anchor>
      <arglist>(tuple&lt; Ts... &gt; const &amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1tuple_a85bd7598dcbb6464a3a89990b0e64aa4.html</anchorfile>
      <anchor>a85bd7598dcbb6464a3a89990b0e64aa4</anchor>
      <arglist>(tuple&lt; Ts... &gt; const &amp;&amp;t) noexcept</arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>kumi::result::unique</name>
    <filename>structkumi_1_1result_1_1unique.html</filename>
    <templarg>kumi::concepts::product_type T</templarg>
  </compound>
  <compound kind="struct">
    <name>kumi::function::unique_t</name>
    <filename>structkumi_1_1function_1_1unique__t.html</filename>
  </compound>
  <compound kind="class">
    <name>kumi::unit</name>
    <filename>structkumi_1_1unit.html</filename>
  </compound>
  <compound kind="class">
    <name>kumi::unknown</name>
    <filename>structkumi_1_1unknown.html</filename>
  </compound>
  <compound kind="struct">
    <name>kumi::result::windows</name>
    <filename>structkumi_1_1result_1_1windows.html</filename>
    <templarg>std::size_t N</templarg>
    <templarg>kumi::concepts::product_type T</templarg>
  </compound>
  <compound kind="struct">
    <name>kumi::result::zip</name>
    <filename>structkumi_1_1result_1_1zip.html</filename>
    <templarg>kumi::concepts::product_type T0</templarg>
    <templarg>kumi::concepts::sized_product_type&lt; kumi::size_v&lt; T0 &gt; &gt;... Ts</templarg>
  </compound>
  <compound kind="struct">
    <name>kumi::result::zip_max</name>
    <filename>structkumi_1_1result_1_1zip__max.html</filename>
    <templarg>kumi::concepts::product_type T0</templarg>
    <templarg>kumi::concepts::product_type... Ts</templarg>
  </compound>
  <compound kind="struct">
    <name>kumi::result::zip_min</name>
    <filename>structkumi_1_1result_1_1zip__min.html</filename>
    <templarg>kumi::concepts::product_type T0</templarg>
    <templarg>kumi::concepts::product_type... Ts</templarg>
  </compound>
  <compound kind="concept">
    <name>kumi::concepts::compatible_product_types</name>
    <filename>conceptkumi_1_1concepts_1_1compatible__product__types.html</filename>
  </compound>
  <compound kind="concept">
    <name>kumi::concepts::container</name>
    <filename>conceptkumi_1_1concepts_1_1container.html</filename>
  </compound>
  <compound kind="concept">
    <name>kumi::concepts::contains_identifier</name>
    <filename>conceptkumi_1_1concepts_1_1contains__identifier.html</filename>
  </compound>
  <compound kind="concept">
    <name>kumi::concepts::contains_label</name>
    <filename>conceptkumi_1_1concepts_1_1contains__label.html</filename>
  </compound>
  <compound kind="concept">
    <name>kumi::concepts::contains_type</name>
    <filename>conceptkumi_1_1concepts_1_1contains__type.html</filename>
  </compound>
  <compound kind="concept">
    <name>kumi::concepts::empty_product_type</name>
    <filename>conceptkumi_1_1concepts_1_1empty__product__type.html</filename>
  </compound>
  <compound kind="concept">
    <name>kumi::concepts::equality_comparable</name>
    <filename>conceptkumi_1_1concepts_1_1equality__comparable.html</filename>
  </compound>
  <compound kind="concept">
    <name>kumi::concepts::equivalent</name>
    <filename>conceptkumi_1_1concepts_1_1equivalent.html</filename>
  </compound>
  <compound kind="concept">
    <name>kumi::concepts::field</name>
    <filename>conceptkumi_1_1concepts_1_1field.html</filename>
  </compound>
  <compound kind="concept">
    <name>kumi::concepts::follows_same_semantic</name>
    <filename>conceptkumi_1_1concepts_1_1follows__same__semantic.html</filename>
  </compound>
  <compound kind="concept">
    <name>kumi::concepts::fully_named</name>
    <filename>conceptkumi_1_1concepts_1_1fully__named.html</filename>
  </compound>
  <compound kind="concept">
    <name>kumi::concepts::has_named_fields</name>
    <filename>conceptkumi_1_1concepts_1_1has__named__fields.html</filename>
  </compound>
  <compound kind="concept">
    <name>kumi::concepts::homogeneous_product_type</name>
    <filename>conceptkumi_1_1concepts_1_1homogeneous__product__type.html</filename>
  </compound>
  <compound kind="concept">
    <name>kumi::concepts::identifier</name>
    <filename>conceptkumi_1_1concepts_1_1identifier.html</filename>
  </compound>
  <compound kind="concept">
    <name>kumi::concepts::index</name>
    <filename>conceptkumi_1_1concepts_1_1index.html</filename>
  </compound>
  <compound kind="concept">
    <name>kumi::concepts::monoid</name>
    <filename>conceptkumi_1_1concepts_1_1monoid.html</filename>
  </compound>
  <compound kind="concept">
    <name>kumi::concepts::non_empty_product_type</name>
    <filename>conceptkumi_1_1concepts_1_1non__empty__product__type.html</filename>
  </compound>
  <compound kind="concept">
    <name>kumi::concepts::product_type</name>
    <filename>conceptkumi_1_1concepts_1_1product__type.html</filename>
  </compound>
  <compound kind="concept">
    <name>kumi::concepts::projection</name>
    <filename>conceptkumi_1_1concepts_1_1projection.html</filename>
  </compound>
  <compound kind="concept">
    <name>kumi::concepts::projection_map</name>
    <filename>conceptkumi_1_1concepts_1_1projection__map.html</filename>
  </compound>
  <compound kind="concept">
    <name>kumi::concepts::queryable_by_identifier</name>
    <filename>conceptkumi_1_1concepts_1_1queryable__by__identifier.html</filename>
  </compound>
  <compound kind="concept">
    <name>kumi::concepts::queryable_by_label</name>
    <filename>conceptkumi_1_1concepts_1_1queryable__by__label.html</filename>
  </compound>
  <compound kind="concept">
    <name>kumi::concepts::record_type</name>
    <filename>conceptkumi_1_1concepts_1_1record__type.html</filename>
  </compound>
  <compound kind="concept">
    <name>kumi::concepts::sized_product_type</name>
    <filename>conceptkumi_1_1concepts_1_1sized__product__type.html</filename>
  </compound>
  <compound kind="concept">
    <name>kumi::concepts::sized_product_type_or_more</name>
    <filename>conceptkumi_1_1concepts_1_1sized__product__type__or__more.html</filename>
  </compound>
  <compound kind="concept">
    <name>kumi::concepts::static_container</name>
    <filename>conceptkumi_1_1concepts_1_1static__container.html</filename>
  </compound>
  <compound kind="concept">
    <name>kumi::concepts::uniquely_labeled</name>
    <filename>conceptkumi_1_1concepts_1_1uniquely__labeled.html</filename>
  </compound>
  <compound kind="concept">
    <name>kumi::concepts::uniquely_named</name>
    <filename>conceptkumi_1_1concepts_1_1uniquely__named.html</filename>
  </compound>
  <compound kind="concept">
    <name>kumi::concepts::uniquely_typed</name>
    <filename>conceptkumi_1_1concepts_1_1uniquely__typed.html</filename>
  </compound>
  <compound kind="concept">
    <name>kumi::concepts::unit_type</name>
    <filename>conceptkumi_1_1concepts_1_1unit__type.html</filename>
  </compound>
  <compound kind="namespace">
    <name>kumi</name>
    <filename>namespacekumi.html</filename>
    <class kind="struct">kumi::all_unique_names</class>
    <class kind="struct">kumi::all_uniques</class>
    <class kind="struct">kumi::apply_traits</class>
    <class kind="class">kumi::as</class>
    <class kind="struct">kumi::as_tuple</class>
    <class kind="class">kumi::builder</class>
    <class kind="struct">kumi::common_product_type</class>
    <class kind="struct">kumi::container_size</class>
    <class kind="struct">kumi::container_type</class>
    <class kind="struct">kumi::element</class>
    <class kind="class">kumi::field</class>
    <class kind="struct">kumi::field&lt; Id, T &gt;</class>
    <class kind="struct">kumi::has_static_size</class>
    <class kind="class">kumi::identifier</class>
    <class kind="class">kumi::index_t</class>
    <class kind="struct">kumi::is_container</class>
    <class kind="struct">kumi::is_equality_comparable</class>
    <class kind="struct">kumi::is_equivalent</class>
    <class kind="struct">kumi::is_homogeneous</class>
    <class kind="struct">kumi::is_product_type</class>
    <class kind="struct">kumi::is_projection_map</class>
    <class kind="struct">kumi::is_record_type</class>
    <class kind="class">kumi::label_t</class>
    <class kind="struct">kumi::map_traits</class>
    <class kind="struct">kumi::member</class>
    <class kind="class">kumi::name</class>
    <class kind="class">kumi::projection_map</class>
    <class kind="class">kumi::record</class>
    <class kind="struct">kumi::size</class>
    <class kind="struct">kumi::stored_element</class>
    <class kind="struct">kumi::stored_member</class>
    <class kind="class">kumi::str</class>
    <class kind="class">kumi::tuple</class>
    <class kind="class">kumi::unit</class>
    <class kind="class">kumi::unknown</class>
    <member kind="function">
      <type>constexpr auto</type>
      <name>bind_back</name>
      <anchorfile>group__functional_ga02fbf71873458cc8a364a7f6efcfadf2.html</anchorfile>
      <anchor>ga02fbf71873458cc8a364a7f6efcfadf2</anchor>
      <arglist>(C &amp;&amp;c, Ts &amp;&amp;... ts) noexcept(std::is_nothrow_move_constructible_v&lt; std::decay_t&lt; C &gt; &gt; &amp;&amp;(std::is_nothrow_move_constructible_v&lt; std::decay_t&lt; Ts &gt; &gt; &amp;&amp;...))</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>bind_front</name>
      <anchorfile>group__functional_ga08c383ce2fb100dda15baf96b4e60d2f.html</anchorfile>
      <anchor>ga08c383ce2fb100dda15baf96b4e60d2f</anchor>
      <arglist>(C &amp;&amp;c, Ts &amp;&amp;... ts) noexcept(std::is_nothrow_move_constructible_v&lt; std::decay_t&lt; C &gt; &gt; &amp;&amp;(std::is_nothrow_move_constructible_v&lt; std::decay_t&lt; Ts &gt; &gt; &amp;&amp;...))</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>field_value_of</name>
      <anchorfile>group__utility_gabf2013046cf8ec8ac781128a815709cc.html</anchorfile>
      <anchor>gabf2013046cf8ec8ac781128a815709cc</anchor>
      <arglist>(T &amp;&amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>consteval auto</type>
      <name>get_index_of_field</name>
      <anchorfile>group__utility_ga2fc46ed70d43d14ca52860896fd1e364.html</anchorfile>
      <anchor>ga2fc46ed70d43d14ca52860896fd1e364</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>consteval auto</type>
      <name>get_index_of_label</name>
      <anchorfile>group__utility_ga6c5b5c12c2baa75189a7d94e55fbfe17.html</anchorfile>
      <anchor>ga6c5b5c12c2baa75189a7d94e55fbfe17</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>consteval auto</type>
      <name>get_index_of_type</name>
      <anchorfile>group__utility_ga15172fcc47fe0c88931be39b9c3633fd.html</anchorfile>
      <anchor>ga15172fcc47fe0c88931be39b9c3633fd</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>consteval auto</type>
      <name>identifier_of</name>
      <anchorfile>group__utility_gab3919ec6f8098dd1fdafe9c3a79ef0dc.html</anchorfile>
      <anchor>gab3919ec6f8098dd1fdafe9c3a79ef0dc</anchor>
      <arglist>() noexcept</arglist>
    </member>
    <member kind="function">
      <type>consteval auto</type>
      <name>identifiers</name>
      <anchorfile>group__utility_ga63a205c6c2502e733987043857abea05.html</anchorfile>
      <anchor>ga63a205c6c2502e733987043857abea05</anchor>
      <arglist>(Ts...) noexcept</arglist>
    </member>
    <member kind="function">
      <type>consteval auto</type>
      <name>indexes</name>
      <anchorfile>group__utility_ga6882a4ada4935fa0fd4ef32ce3716ffb.html</anchorfile>
      <anchor>ga6882a4ada4935fa0fd4ef32ce3716ffb</anchor>
      <arglist>(Ts...) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>invoke</name>
      <anchorfile>group__functional_gace270cfbaa7b0d519fdf03f8225f2908.html</anchorfile>
      <anchor>gace270cfbaa7b0d519fdf03f8225f2908</anchor>
      <arglist>(C &amp;&amp;c, Ts &amp;&amp;... ts)</arglist>
    </member>
    <member kind="function">
      <type>constexpr R</type>
      <name>invoke_r</name>
      <anchorfile>group__functional_ga2ad666793ad04ea9b66c84b83f41f375.html</anchorfile>
      <anchor>ga2ad666793ad04ea9b66c84b83f41f375</anchor>
      <arglist>(C &amp;&amp;c, Ts &amp;&amp;... ts) noexcept(std::is_nothrow_invocable_r_v&lt; R, C, Ts... &gt;)</arglist>
    </member>
    <member kind="function">
      <type>consteval str</type>
      <name>label_of</name>
      <anchorfile>group__utility_gafe5ca3b16c26d385085be7a73a1fa374.html</anchorfile>
      <anchor>gafe5ca3b16c26d385085be7a73a1fa374</anchor>
      <arglist>() noexcept</arglist>
    </member>
    <member kind="function">
      <type>consteval auto</type>
      <name>make_indexes</name>
      <anchorfile>group__utility_gadba148c334bcf52088dc64992c270fdd.html</anchorfile>
      <anchor>gadba148c334bcf52088dc64992c270fdd</anchor>
      <arglist>() noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>operator&quot;&quot;_c</name>
      <anchorfile>group__utility_ga60825dffaa5ee2c50e1d1a24057bdcf1.html</anchorfile>
      <anchor>ga60825dffaa5ee2c50e1d1a24057bdcf1</anchor>
      <arglist>() noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>operator&quot;&quot;_id</name>
      <anchorfile>group__utility_ga10f2338fc8867a50a4295325873f3de4.html</anchorfile>
      <anchor>ga10f2338fc8867a50a4295325873f3de4</anchor>
      <arglist>() noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>operator&quot;&quot;_l</name>
      <anchorfile>group__utility_ga1eb529eb7ccadf0b5e632c132c2b9750.html</anchorfile>
      <anchor>ga1eb529eb7ccadf0b5e632c132c2b9750</anchor>
      <arglist>() noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr bool</type>
      <name>operator==</name>
      <anchorfile>namespacekumi.html</anchorfile>
      <anchor>a79ad96867cb40b26d3f8929df3177aad</anchor>
      <arglist>(L const &amp;, R const &amp;)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>predicate</name>
      <anchorfile>group__utility_ga9c8c29e8a2f4f5e8a663200559fdc983.html</anchorfile>
      <anchor>ga9c8c29e8a2f4f5e8a663200559fdc983</anchor>
      <arglist>() noexcept</arglist>
    </member>
    <member kind="function">
      <type>KUMI_CUDA</type>
      <name>projection_map</name>
      <anchorfile>group__utility_ga8b7f4e6ed1e7071d7c152c9870709fcb.html</anchorfile>
      <anchor>ga8b7f4e6ed1e7071d7c152c9870709fcb</anchor>
      <arglist>(Ts...) -&gt; projection_map&lt; Ts</arglist>
    </member>
    <member kind="variable">
      <type>constexpr all_of_t</type>
      <name>all_of</name>
      <anchorfile>group__queries_gaffdb8063b72f079107cd8a7e293ba298.html</anchorfile>
      <anchor>gaffdb8063b72f079107cd8a7e293ba298</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr all_unique_t</type>
      <name>all_unique</name>
      <anchorfile>group__generators_ga71bbbe8da94919e242bd3ded80ab6776.html</anchorfile>
      <anchor>ga71bbbe8da94919e242bd3ded80ab6776</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr any_of_t</type>
      <name>any_of</name>
      <anchorfile>group__queries_ga79566892f932a2308e23b5f21b95086f.html</anchorfile>
      <anchor>ga79566892f932a2308e23b5f21b95086f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr apply_t</type>
      <name>apply</name>
      <anchorfile>group__transforms_ga4c69a49971100b7bc9c7effd7c43f191.html</anchorfile>
      <anchor>ga4c69a49971100b7bc9c7effd7c43f191</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr apply_field_t</type>
      <name>apply_field</name>
      <anchorfile>group__transforms_ga992364930a4a5a5b64b26730773536ab.html</anchorfile>
      <anchor>ga992364930a4a5a5b64b26730773536ab</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr as_flat_ptr_t</type>
      <name>as_flat_ptr</name>
      <anchorfile>group__generators_ga6368952a2f6a506de75aa0e01569eab6.html</anchorfile>
      <anchor>ga6368952a2f6a506de75aa0e01569eab6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr back_t</type>
      <name>back</name>
      <anchorfile>group__queries_gae635e0c094282372ff5393840b6f52c2.html</anchorfile>
      <anchor>gae635e0c094282372ff5393840b6f52c2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr bit_and_t</type>
      <name>bit_and</name>
      <anchorfile>group__reductions_ga17c3d8bab8099c4756a8b6fb4e9d4380.html</anchorfile>
      <anchor>ga17c3d8bab8099c4756a8b6fb4e9d4380</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr bit_or_t</type>
      <name>bit_or</name>
      <anchorfile>group__reductions_ga74fa99e87e80d8bb15ea6694e381bd49.html</anchorfile>
      <anchor>ga74fa99e87e80d8bb15ea6694e381bd49</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr bit_xor_t</type>
      <name>bit_xor</name>
      <anchorfile>group__reductions_ga2797c81f32afec2f2ce4856a5155807c.html</anchorfile>
      <anchor>ga2797c81f32afec2f2ce4856a5155807c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr cartesian_product_t</type>
      <name>cartesian_product</name>
      <anchorfile>group__generators_ga39128fad2c11b9fea55558222a87721c.html</anchorfile>
      <anchor>ga39128fad2c11b9fea55558222a87721c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr cat_t</type>
      <name>cat</name>
      <anchorfile>group__generators_ga4550222df58187f71b1b1347500e324a.html</anchorfile>
      <anchor>ga4550222df58187f71b1b1347500e324a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr tiles_t&lt; N, N &gt;</type>
      <name>chunks</name>
      <anchorfile>group__generators_gaf4b0bcda72790c2ac55519adaf89456e.html</anchorfile>
      <anchor>gaf4b0bcda72790c2ac55519adaf89456e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr compress_t</type>
      <name>compress</name>
      <anchorfile>group__generators_gaa9d6196838118af0a837160d8bbf532c.html</anchorfile>
      <anchor>gaa9d6196838118af0a837160d8bbf532c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr contains_t</type>
      <name>contains</name>
      <anchorfile>group__queries_ga3a9b6e2d0fbdace9e57b3846d24a3b57.html</anchorfile>
      <anchor>ga3a9b6e2d0fbdace9e57b3846d24a3b57</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr contains_any_t</type>
      <name>contains_any</name>
      <anchorfile>group__queries_ga639f59cb294f670d2f2c468c4ef204d3.html</anchorfile>
      <anchor>ga639f59cb294f670d2f2c468c4ef204d3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr contains_none_t</type>
      <name>contains_none</name>
      <anchorfile>group__queries_ga7b1bbe80c513abfdedd1196f027601d2.html</anchorfile>
      <anchor>ga7b1bbe80c513abfdedd1196f027601d2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr contains_only_t</type>
      <name>contains_only</name>
      <anchorfile>group__queries_ga36431211bf121466392b290459a45498.html</anchorfile>
      <anchor>ga36431211bf121466392b290459a45498</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr count_t</type>
      <name>count</name>
      <anchorfile>group__queries_ga8240f113b5feb1dcc826949f28f17a47.html</anchorfile>
      <anchor>ga8240f113b5feb1dcc826949f28f17a47</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr count_if_t</type>
      <name>count_if</name>
      <anchorfile>group__queries_gaec0fb27dc2250b97648bc52b8e83b561.html</anchorfile>
      <anchor>gaec0fb27dc2250b97648bc52b8e83b561</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr exclusive_scan_left_t</type>
      <name>exclusive_scan_left</name>
      <anchorfile>group__reductions_ga529950ddf6573473b2f9b7ec886c61f9.html</anchorfile>
      <anchor>ga529950ddf6573473b2f9b7ec886c61f9</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr exclusive_scan_right_t</type>
      <name>exclusive_scan_right</name>
      <anchorfile>group__reductions_gaa66bb36d76db2d7854196bc156fb35c2.html</anchorfile>
      <anchor>gaa66bb36d76db2d7854196bc156fb35c2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr extract_t</type>
      <name>extract</name>
      <anchorfile>group__generators_ga1a7617bafd6f8598cca8e7e6a5c6f383.html</anchorfile>
      <anchor>ga1a7617bafd6f8598cca8e7e6a5c6f383</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr fill_t&lt; N &gt;</type>
      <name>fill</name>
      <anchorfile>group__generators_gafd5d1c6d3d2fcb3c424826b8bddb8b0a.html</anchorfile>
      <anchor>gafd5d1c6d3d2fcb3c424826b8bddb8b0a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr filter_t&lt; Pred &gt;</type>
      <name>filter</name>
      <anchorfile>group__generators_ga2c9b5ff6b698c7dcb0feb2da1679fa9b.html</anchorfile>
      <anchor>ga2c9b5ff6b698c7dcb0feb2da1679fa9b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr filter_not_t&lt; Pred &gt;</type>
      <name>filter_not</name>
      <anchorfile>group__generators_ga750bc3d3425c955e1be6ef1b3879c314.html</anchorfile>
      <anchor>ga750bc3d3425c955e1be6ef1b3879c314</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr flatten_t</type>
      <name>flatten</name>
      <anchorfile>group__generators_ga49acccc42ec8af7b96b63e8f38796df2.html</anchorfile>
      <anchor>ga49acccc42ec8af7b96b63e8f38796df2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr flatten_all_t</type>
      <name>flatten_all</name>
      <anchorfile>group__generators_gaa780fd338fb61c86f226ae05adfaf426.html</anchorfile>
      <anchor>gaa780fd338fb61c86f226ae05adfaf426</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr fold_left_t</type>
      <name>fold_left</name>
      <anchorfile>group__reductions_gac7fc6bc4e0aff96cca71f0a64b0f2aa1.html</anchorfile>
      <anchor>gac7fc6bc4e0aff96cca71f0a64b0f2aa1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr fold_right_t</type>
      <name>fold_right</name>
      <anchorfile>group__reductions_gaee418c18e09e3b1789c23ec00681db42.html</anchorfile>
      <anchor>gaee418c18e09e3b1789c23ec00681db42</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr for_each_t</type>
      <name>for_each</name>
      <anchorfile>group__transforms_ga58c4bb5e62083b4b37396d39c6446164.html</anchorfile>
      <anchor>ga58c4bb5e62083b4b37396d39c6446164</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr front_t</type>
      <name>front</name>
      <anchorfile>group__queries_gaa1618c96c4c7003afeccfb19e25b35bb.html</anchorfile>
      <anchor>gaa1618c96c4c7003afeccfb19e25b35bb</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr generate_t&lt; N &gt;</type>
      <name>generate</name>
      <anchorfile>group__generators_gaba2efbda8df6baaccd4e35343d70163f.html</anchorfile>
      <anchor>gaba2efbda8df6baaccd4e35343d70163f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr traits_check&lt; Traits &gt;</type>
      <name>if_</name>
      <anchorfile>group__utility_gacadc026868e6654e80c57432643c804a.html</anchorfile>
      <anchor>gacadc026868e6654e80c57432643c804a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr inclusive_scan_left_t</type>
      <name>inclusive_scan_left</name>
      <anchorfile>group__reductions_ga1389eee6fb884b34ed4957884ecd39a1.html</anchorfile>
      <anchor>ga1389eee6fb884b34ed4957884ecd39a1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr inclusive_scan_right_t</type>
      <name>inclusive_scan_right</name>
      <anchorfile>group__reductions_gab55848ee4bd1b0cc0f22015a2bac5047.html</anchorfile>
      <anchor>gab55848ee4bd1b0cc0f22015a2bac5047</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr kumi::index_t&lt; N &gt; const</type>
      <name>index</name>
      <anchorfile>group__utility.html</anchorfile>
      <anchor>gaa1c76fca002e966a0a40e311ad68d841</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr iota_t&lt; N &gt;</type>
      <name>iota</name>
      <anchorfile>group__generators_gace6e022bb94a706731299b9d395ac10d.html</anchorfile>
      <anchor>gace6e022bb94a706731299b9d395ac10d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr kumi::label_t&lt; Label &gt;</type>
      <name>label</name>
      <anchorfile>group__utility.html</anchorfile>
      <anchor>ga1375bb29a75ab718bdb62b65ce5582b1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr locate_t</type>
      <name>locate</name>
      <anchorfile>group__queries_ga39f807d6c2b8909a712d431acde4153e.html</anchorfile>
      <anchor>ga39f807d6c2b8909a712d431acde4153e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr map_t</type>
      <name>map</name>
      <anchorfile>group__transforms_gaeaba737291ba1085d77272eae38a016e.html</anchorfile>
      <anchor>gaeaba737291ba1085d77272eae38a016e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr map_field_t</type>
      <name>map_field</name>
      <anchorfile>group__record__transforms_gafe68ca583e3e822b20f60ff35e5aa9d3.html</anchorfile>
      <anchor>gafe68ca583e3e822b20f60ff35e5aa9d3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr map_index_t</type>
      <name>map_index</name>
      <anchorfile>group__tuple__transforms_ga64a8c36072828fb7b724ba0ab8fc59bc.html</anchorfile>
      <anchor>ga64a8c36072828fb7b724ba0ab8fc59bc</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr map_reduce_t</type>
      <name>map_reduce</name>
      <anchorfile>group__reductions_ga396afbfbcefa48f06ad76a34b6f0b523.html</anchorfile>
      <anchor>ga396afbfbcefa48f06ad76a34b6f0b523</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr max_t</type>
      <name>max</name>
      <anchorfile>group__reductions_gab76e53ad197280669806cae2c0cc130c.html</anchorfile>
      <anchor>gab76e53ad197280669806cae2c0cc130c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr member_cast_t&lt; T &gt;</type>
      <name>member_cast</name>
      <anchorfile>group__generators_gad2e4009d5d28df5090885b030f08f1f8.html</anchorfile>
      <anchor>gad2e4009d5d28df5090885b030f08f1f8</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr min_t</type>
      <name>min</name>
      <anchorfile>group__reductions_gaafd0c178628f6f756bf0d73a34e75b2f.html</anchorfile>
      <anchor>gaafd0c178628f6f756bf0d73a34e75b2f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr kumi::unit</type>
      <name>none</name>
      <anchorfile>group__utility.html</anchorfile>
      <anchor>gae57a2a957d7c5dc2c0b3d21e0b1a98c0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr none_of_t</type>
      <name>none_of</name>
      <anchorfile>group__queries_ga26e030c97733248f67dd2c8fbf527602.html</anchorfile>
      <anchor>ga26e030c97733248f67dd2c8fbf527602</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr kumi::only_t&lt; T &gt;</type>
      <name>only</name>
      <anchorfile>group__utility_ga26690952147eaa66ecf74378070ee53b.html</anchorfile>
      <anchor>ga26690952147eaa66ecf74378070ee53b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr partition_t&lt; Pred &gt;</type>
      <name>partition</name>
      <anchorfile>group__generators_ga4643116b2dc0dfbd0d15fee408a9c18c.html</anchorfile>
      <anchor>ga4643116b2dc0dfbd0d15fee408a9c18c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr pop_front_t</type>
      <name>pop_front</name>
      <anchorfile>group__generators_ga38d1ddeb5090405e79e9b7d898a85133.html</anchorfile>
      <anchor>ga38d1ddeb5090405e79e9b7d898a85133</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr prod_t</type>
      <name>prod</name>
      <anchorfile>group__reductions_ga6c139ebafaebc0f7dbca2fd57aee943c.html</anchorfile>
      <anchor>ga6c139ebafaebc0f7dbca2fd57aee943c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr push_front_t</type>
      <name>push_front</name>
      <anchorfile>group__generators_gad4bd53f162f63af0cbfbd68d8adb5d5c.html</anchorfile>
      <anchor>gad4bd53f162f63af0cbfbd68d8adb5d5c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr reduce_t</type>
      <name>reduce</name>
      <anchorfile>group__reductions_gaf7efbfa530d2396e2ed230cc03e4046e.html</anchorfile>
      <anchor>gaf7efbfa530d2396e2ed230cc03e4046e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr reindex_t&lt; Projections &gt;</type>
      <name>reindex</name>
      <anchorfile>group__generators_ga3594f15dbfba2f6fda0afc8d1542c449.html</anchorfile>
      <anchor>ga3594f15dbfba2f6fda0afc8d1542c449</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr remove_t</type>
      <name>remove</name>
      <anchorfile>group__generators_ga0f52ba0b24ce54052784df91c54ac233.html</anchorfile>
      <anchor>ga0f52ba0b24ce54052784df91c54ac233</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr reorder_t&lt; I... &gt;</type>
      <name>reorder</name>
      <anchorfile>group__generators_ga32af967d7f453426ccd564d3a0b6c689.html</anchorfile>
      <anchor>ga32af967d7f453426ccd564d3a0b6c689</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr reorder_fields_t&lt; Name... &gt;</type>
      <name>reorder_fields</name>
      <anchorfile>group__generators_ga8c42552c8f93dad0b83a3903468d02c6.html</anchorfile>
      <anchor>ga8c42552c8f93dad0b83a3903468d02c6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr rotate_left_t&lt; R &gt;</type>
      <name>rotate_left</name>
      <anchorfile>group__generators_gadbc56977f82e2eaefe486c0a9457f01c.html</anchorfile>
      <anchor>gadbc56977f82e2eaefe486c0a9457f01c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr rotate_right_t&lt; R &gt;</type>
      <name>rotate_right</name>
      <anchorfile>group__generators_gaffd5dbb36e1c70d2fc058ffe03afef3e.html</anchorfile>
      <anchor>gaffd5dbb36e1c70d2fc058ffe03afef3e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr split_t</type>
      <name>split</name>
      <anchorfile>group__generators_gadb81f4533e81830674c3fc9577d3de93.html</anchorfile>
      <anchor>gadb81f4533e81830674c3fc9577d3de93</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr sum_t</type>
      <name>sum</name>
      <anchorfile>group__reductions_ga3e8b585399de360c3ab55efc2fa0ed8c.html</anchorfile>
      <anchor>ga3e8b585399de360c3ab55efc2fa0ed8c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr tiles_t&lt; N, O &gt;</type>
      <name>tiles</name>
      <anchorfile>group__generators_ga3d1b4a8309328d854d7b6234fde3aeb0.html</anchorfile>
      <anchor>ga3d1b4a8309328d854d7b6234fde3aeb0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr transpose_t</type>
      <name>transpose</name>
      <anchorfile>group__generators_gaef527bdd76c70e7fded23a9759428f5c.html</anchorfile>
      <anchor>gaef527bdd76c70e7fded23a9759428f5c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr unique_t</type>
      <name>unique</name>
      <anchorfile>group__generators_ga6479cba59ee95d4a0779e94993ab55a9.html</anchorfile>
      <anchor>ga6479cba59ee95d4a0779e94993ab55a9</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr tiles_t&lt; N, 1 &gt;</type>
      <name>windows</name>
      <anchorfile>group__generators_gade96292292ae11da69415a778ef45ad0.html</anchorfile>
      <anchor>gade96292292ae11da69415a778ef45ad0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr zip_t</type>
      <name>zip</name>
      <anchorfile>group__generators_ga71c21174289ba175a8d3d4b170cec05f.html</anchorfile>
      <anchor>ga71c21174289ba175a8d3d4b170cec05f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr zip_max_t</type>
      <name>zip_max</name>
      <anchorfile>group__generators_ga0ce4823febfb00cfb197f73332ba7309.html</anchorfile>
      <anchor>ga0ce4823febfb00cfb197f73332ba7309</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr zip_min_t</type>
      <name>zip_min</name>
      <anchorfile>group__generators_gaf4b9aea3cee7c30fc6a516c632805423.html</anchorfile>
      <anchor>gaf4b9aea3cee7c30fc6a516c632805423</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>from_tuple</name>
      <anchorfile>group__tuple__related_ga81cca523672d8799bbe35fa4f07dd61f.html</anchorfile>
      <anchor>ga81cca523672d8799bbe35fa4f07dd61f</anchor>
      <arglist>(tuple&lt; Ts... &gt; const &amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>to_tuple</name>
      <anchorfile>group__tuple__related_ga0bacdab2d5c18c44431ba8f74b86a5f0.html</anchorfile>
      <anchor>ga0bacdab2d5c18c44431ba8f74b86a5f0</anchor>
      <arglist>(T &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>to_tuple</name>
      <anchorfile>namespacekumi.html</anchorfile>
      <anchor>a8d48ba398b636ca4b3f31662283701f0</anchor>
      <arglist>(S &amp;&amp;s)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>tie</name>
      <anchorfile>group__record__related_ga9d6e39a733f56863dfa21cb1f07fdc3a.html</anchorfile>
      <anchor>ga9d6e39a733f56863dfa21cb1f07fdc3a</anchor>
      <arglist>(Ts &amp;... ts) -&gt; kumi::record&lt; kumi::field&lt; decltype(Fields), Ts &amp; &gt;... &gt; requires(sizeof...(Fields)==sizeof...(Ts))</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>forward_as_record</name>
      <anchorfile>group__record__related_gaa0d291bc5523e9e07e5c38559e0dcb3d.html</anchorfile>
      <anchor>gaa0d291bc5523e9e07e5c38559e0dcb3d</anchor>
      <arglist>(Ts &amp;&amp;... ts) -&gt; kumi::record&lt; kumi::field&lt; decltype(Fields), Ts &amp;&amp; &gt;... &gt; requires(sizeof...(Fields)==sizeof...(Ts))</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>make_record</name>
      <anchorfile>group__record__related_ga96da0243ca4cf9e490f62c327f51fe4e.html</anchorfile>
      <anchor>ga96da0243ca4cf9e490f62c327f51fe4e</anchor>
      <arglist>(Ts &amp;&amp;... ts) -&gt; kumi::record&lt; std::unwrap_ref_decay_t&lt; Ts &gt;... &gt; requires(kumi::concepts::uniquely_named&lt; Ts... &gt; &amp;&amp;kumi::concepts::fully_named&lt; Ts... &gt;)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>to_ref</name>
      <anchorfile>group__record__related_ga83a97fc306d9ecfacde28584b219b44a.html</anchorfile>
      <anchor>ga83a97fc306d9ecfacde28584b219b44a</anchor>
      <arglist>(R &amp;&amp;r)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>from_record</name>
      <anchorfile>group__record__related_ga772ac1518ac3bbe1627db9c00f56abdd.html</anchorfile>
      <anchor>ga772ac1518ac3bbe1627db9c00f56abdd</anchor>
      <arglist>(record&lt; Ts... &gt; const &amp;r)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>to_record</name>
      <anchorfile>group__record__related_ga324cc6775ad5b15767fc2eaae02abd73.html</anchorfile>
      <anchor>ga324cc6775ad5b15767fc2eaae02abd73</anchor>
      <arglist>(Type &amp;&amp;r)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>tie</name>
      <anchorfile>group__tuple__related_ga834fa03c64e67b8bdebccec00e9d195b.html</anchorfile>
      <anchor>ga834fa03c64e67b8bdebccec00e9d195b</anchor>
      <arglist>(Ts &amp;... ts) -&gt; kumi::tuple&lt; Ts &amp;... &gt;</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>forward_as_tuple</name>
      <anchorfile>group__tuple__related_gac167a1000c9c61798b7d8c684f3c804b.html</anchorfile>
      <anchor>gac167a1000c9c61798b7d8c684f3c804b</anchor>
      <arglist>(Ts &amp;&amp;... ts) -&gt; kumi::tuple&lt; Ts &amp;&amp;... &gt;</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>make_tuple</name>
      <anchorfile>group__tuple__related_ga8570ddb839f6b158633537fd7113e795.html</anchorfile>
      <anchor>ga8570ddb839f6b158633537fd7113e795</anchor>
      <arglist>(Ts &amp;&amp;... ts) -&gt; kumi::tuple&lt; std::unwrap_ref_decay_t&lt; Ts &gt;... &gt;</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>to_ref</name>
      <anchorfile>group__tuple__related_ga727f8ab64140ca60bcb1c8aded343c0b.html</anchorfile>
      <anchor>ga727f8ab64140ca60bcb1c8aded343c0b</anchor>
      <arglist>(T &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>KUMI_CUDA</type>
      <name>record</name>
      <anchorfile>structkumi_1_1record_a1000cb0996a9587f8735a35f76060e44.html</anchorfile>
      <anchor>a1000cb0996a9587f8735a35f76060e44</anchor>
      <arglist>(Ts &amp;&amp;...) -&gt; record&lt; std::unwrap_ref_decay_t&lt; Ts &gt;... &gt;</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1record_abc2cd329ad25d155458850c19cc3b137.html</anchorfile>
      <anchor>abc2cd329ad25d155458850c19cc3b137</anchor>
      <arglist>(record&lt; Ts... &gt; &amp;r) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1record_add6a786a9f4cf8a88d85f0b3b88d4705.html</anchorfile>
      <anchor>add6a786a9f4cf8a88d85f0b3b88d4705</anchor>
      <arglist>(record&lt; Ts... &gt; &amp;&amp;r) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1record_a275ab6e86c6128f8f5e2c30ef3f26c4f.html</anchorfile>
      <anchor>a275ab6e86c6128f8f5e2c30ef3f26c4f</anchor>
      <arglist>(record&lt; Ts... &gt; const &amp;r) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1record_a3dc6eb9adc6e77531fe60520794558a5.html</anchorfile>
      <anchor>a3dc6eb9adc6e77531fe60520794558a5</anchor>
      <arglist>(record&lt; Ts... &gt; const &amp;&amp;r) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1record_abc2cd329ad25d155458850c19cc3b137.html</anchorfile>
      <anchor>abc2cd329ad25d155458850c19cc3b137</anchor>
      <arglist>(record&lt; Ts... &gt; &amp;r) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1record_add6a786a9f4cf8a88d85f0b3b88d4705.html</anchorfile>
      <anchor>add6a786a9f4cf8a88d85f0b3b88d4705</anchor>
      <arglist>(record&lt; Ts... &gt; &amp;&amp;r) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1record_a275ab6e86c6128f8f5e2c30ef3f26c4f.html</anchorfile>
      <anchor>a275ab6e86c6128f8f5e2c30ef3f26c4f</anchor>
      <arglist>(record&lt; Ts... &gt; const &amp;r) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1record_a3dc6eb9adc6e77531fe60520794558a5.html</anchorfile>
      <anchor>a3dc6eb9adc6e77531fe60520794558a5</anchor>
      <arglist>(record&lt; Ts... &gt; const &amp;&amp;r) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1record_abc2cd329ad25d155458850c19cc3b137.html</anchorfile>
      <anchor>abc2cd329ad25d155458850c19cc3b137</anchor>
      <arglist>(record&lt; Ts... &gt; &amp;r) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1record_add6a786a9f4cf8a88d85f0b3b88d4705.html</anchorfile>
      <anchor>add6a786a9f4cf8a88d85f0b3b88d4705</anchor>
      <arglist>(record&lt; Ts... &gt; &amp;&amp;r) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1record_a275ab6e86c6128f8f5e2c30ef3f26c4f.html</anchorfile>
      <anchor>a275ab6e86c6128f8f5e2c30ef3f26c4f</anchor>
      <arglist>(record&lt; Ts... &gt; const &amp;r) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1record_a3dc6eb9adc6e77531fe60520794558a5.html</anchorfile>
      <anchor>a3dc6eb9adc6e77531fe60520794558a5</anchor>
      <arglist>(record&lt; Ts... &gt; const &amp;&amp;r) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1record_abc2cd329ad25d155458850c19cc3b137.html</anchorfile>
      <anchor>abc2cd329ad25d155458850c19cc3b137</anchor>
      <arglist>(record&lt; Ts... &gt; &amp;r) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1record_add6a786a9f4cf8a88d85f0b3b88d4705.html</anchorfile>
      <anchor>add6a786a9f4cf8a88d85f0b3b88d4705</anchor>
      <arglist>(record&lt; Ts... &gt; &amp;&amp;r) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1record_a275ab6e86c6128f8f5e2c30ef3f26c4f.html</anchorfile>
      <anchor>a275ab6e86c6128f8f5e2c30ef3f26c4f</anchor>
      <arglist>(record&lt; Ts... &gt; const &amp;r) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1record_a3dc6eb9adc6e77531fe60520794558a5.html</anchorfile>
      <anchor>a3dc6eb9adc6e77531fe60520794558a5</anchor>
      <arglist>(record&lt; Ts... &gt; const &amp;&amp;r) noexcept</arglist>
    </member>
    <member kind="function">
      <type>KUMI_CUDA</type>
      <name>tuple</name>
      <anchorfile>structkumi_1_1tuple_a889b9718ac16b1be40acc38689401cd1.html</anchorfile>
      <anchor>a889b9718ac16b1be40acc38689401cd1</anchor>
      <arglist>(Ts &amp;&amp;...) -&gt; tuple&lt; std::unwrap_ref_decay_t&lt; Ts &gt;... &gt;</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>members_of</name>
      <anchorfile>structkumi_1_1tuple_ac67c6dbee8bf12133da3379826cde848.html</anchorfile>
      <anchor>ac67c6dbee8bf12133da3379826cde848</anchor>
      <arglist>(as&lt; T &gt;) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>values_of</name>
      <anchorfile>structkumi_1_1tuple_ade5f616b3115a74bd4930f70f96ca199.html</anchorfile>
      <anchor>ade5f616b3115a74bd4930f70f96ca199</anchor>
      <arglist>(T &amp;&amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1tuple_a7b9b1b3fbe3d201542691bee350d8a08.html</anchorfile>
      <anchor>a7b9b1b3fbe3d201542691bee350d8a08</anchor>
      <arglist>(tuple&lt; Ts... &gt; &amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1tuple_a808bbc50bf9ed9681c41b55f5444e9ea.html</anchorfile>
      <anchor>a808bbc50bf9ed9681c41b55f5444e9ea</anchor>
      <arglist>(tuple&lt; Ts... &gt; &amp;&amp;arg) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1tuple_adcfd380d3fc78581e99125f49e32ae0a.html</anchorfile>
      <anchor>adcfd380d3fc78581e99125f49e32ae0a</anchor>
      <arglist>(tuple&lt; Ts... &gt; const &amp;arg) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1tuple_aaea300b4c7c7cbe1103612b28ba470b5.html</anchorfile>
      <anchor>aaea300b4c7c7cbe1103612b28ba470b5</anchor>
      <arglist>(tuple&lt; Ts... &gt; const &amp;&amp;arg) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1tuple_a7b9b1b3fbe3d201542691bee350d8a08.html</anchorfile>
      <anchor>a7b9b1b3fbe3d201542691bee350d8a08</anchor>
      <arglist>(tuple&lt; Ts... &gt; &amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1tuple_a83e0ac15f8a19c27cfa885b662daed27.html</anchorfile>
      <anchor>a83e0ac15f8a19c27cfa885b662daed27</anchor>
      <arglist>(tuple&lt; Ts... &gt; &amp;&amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1tuple_a7a96007c3fe14162df0e69e6dee3ed96.html</anchorfile>
      <anchor>a7a96007c3fe14162df0e69e6dee3ed96</anchor>
      <arglist>(tuple&lt; Ts... &gt; const &amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1tuple_a85bd7598dcbb6464a3a89990b0e64aa4.html</anchorfile>
      <anchor>a85bd7598dcbb6464a3a89990b0e64aa4</anchor>
      <arglist>(tuple&lt; Ts... &gt; const &amp;&amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1tuple_a7b9b1b3fbe3d201542691bee350d8a08.html</anchorfile>
      <anchor>a7b9b1b3fbe3d201542691bee350d8a08</anchor>
      <arglist>(tuple&lt; Ts... &gt; &amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1tuple_a83e0ac15f8a19c27cfa885b662daed27.html</anchorfile>
      <anchor>a83e0ac15f8a19c27cfa885b662daed27</anchor>
      <arglist>(tuple&lt; Ts... &gt; &amp;&amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1tuple_a7a96007c3fe14162df0e69e6dee3ed96.html</anchorfile>
      <anchor>a7a96007c3fe14162df0e69e6dee3ed96</anchor>
      <arglist>(tuple&lt; Ts... &gt; const &amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1tuple_a85bd7598dcbb6464a3a89990b0e64aa4.html</anchorfile>
      <anchor>a85bd7598dcbb6464a3a89990b0e64aa4</anchor>
      <arglist>(tuple&lt; Ts... &gt; const &amp;&amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1tuple_a7b9b1b3fbe3d201542691bee350d8a08.html</anchorfile>
      <anchor>a7b9b1b3fbe3d201542691bee350d8a08</anchor>
      <arglist>(tuple&lt; Ts... &gt; &amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1tuple_a83e0ac15f8a19c27cfa885b662daed27.html</anchorfile>
      <anchor>a83e0ac15f8a19c27cfa885b662daed27</anchor>
      <arglist>(tuple&lt; Ts... &gt; &amp;&amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1tuple_a7a96007c3fe14162df0e69e6dee3ed96.html</anchorfile>
      <anchor>a7a96007c3fe14162df0e69e6dee3ed96</anchor>
      <arglist>(tuple&lt; Ts... &gt; const &amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1tuple_a85bd7598dcbb6464a3a89990b0e64aa4.html</anchorfile>
      <anchor>a85bd7598dcbb6464a3a89990b0e64aa4</anchor>
      <arglist>(tuple&lt; Ts... &gt; const &amp;&amp;t) noexcept</arglist>
    </member>
  </compound>
  <compound kind="namespace">
    <name>literals</name>
    <filename>namespaceliterals.html</filename>
  </compound>
  <compound kind="group">
    <name>details</name>
    <title>Helper Types and Functions</title>
    <filename>group__details.html</filename>
  </compound>
  <compound kind="group">
    <name>utility</name>
    <title>Helper Types and Functions</title>
    <filename>group__utility.html</filename>
    <class kind="class">kumi::builder</class>
    <class kind="class">kumi::projection_map</class>
    <member kind="function">
      <type>auto</type>
      <name>as_streamable</name>
      <anchorfile>group__utility_gae8a72b55c5e0a89b70663342e2c36eaf.html</anchorfile>
      <anchor>gae8a72b55c5e0a89b70663342e2c36eaf</anchor>
      <arglist>(auto e)</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>kumi::field::capture_field</name>
      <anchorfile>group__utility_gafc8e80ba53336a0142f3267959c1ba71.html</anchorfile>
      <anchor>gafc8e80ba53336a0142f3267959c1ba71</anchor>
      <arglist>(T &amp;&amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>kumi::field::field_cast</name>
      <anchorfile>group__utility_ga59477c1d8542af2601f493e3320434ee.html</anchorfile>
      <anchor>ga59477c1d8542af2601f493e3320434ee</anchor>
      <arglist>(T &amp;&amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>kumi::field_value_of</name>
      <anchorfile>group__utility_gabf2013046cf8ec8ac781128a815709cc.html</anchorfile>
      <anchor>gabf2013046cf8ec8ac781128a815709cc</anchor>
      <arglist>(T &amp;&amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>consteval auto</type>
      <name>kumi::get_index_of_field</name>
      <anchorfile>group__utility_ga2fc46ed70d43d14ca52860896fd1e364.html</anchorfile>
      <anchor>ga2fc46ed70d43d14ca52860896fd1e364</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>consteval auto</type>
      <name>kumi::get_index_of_label</name>
      <anchorfile>group__utility_ga6c5b5c12c2baa75189a7d94e55fbfe17.html</anchorfile>
      <anchor>ga6c5b5c12c2baa75189a7d94e55fbfe17</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>consteval auto</type>
      <name>kumi::get_index_of_type</name>
      <anchorfile>group__utility_ga15172fcc47fe0c88931be39b9c3633fd.html</anchorfile>
      <anchor>ga15172fcc47fe0c88931be39b9c3633fd</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>consteval auto</type>
      <name>kumi::identifier_of</name>
      <anchorfile>group__utility_gab3919ec6f8098dd1fdafe9c3a79ef0dc.html</anchorfile>
      <anchor>gab3919ec6f8098dd1fdafe9c3a79ef0dc</anchor>
      <arglist>() noexcept</arglist>
    </member>
    <member kind="function">
      <type>consteval auto</type>
      <name>kumi::identifiers</name>
      <anchorfile>group__utility_ga63a205c6c2502e733987043857abea05.html</anchorfile>
      <anchor>ga63a205c6c2502e733987043857abea05</anchor>
      <arglist>(Ts...) noexcept</arglist>
    </member>
    <member kind="function">
      <type>consteval auto</type>
      <name>kumi::indexes</name>
      <anchorfile>group__utility_ga6882a4ada4935fa0fd4ef32ce3716ffb.html</anchorfile>
      <anchor>ga6882a4ada4935fa0fd4ef32ce3716ffb</anchor>
      <arglist>(Ts...) noexcept</arglist>
    </member>
    <member kind="function">
      <type>consteval str</type>
      <name>kumi::label_of</name>
      <anchorfile>group__utility_gafe5ca3b16c26d385085be7a73a1fa374.html</anchorfile>
      <anchor>gafe5ca3b16c26d385085be7a73a1fa374</anchor>
      <arglist>() noexcept</arglist>
    </member>
    <member kind="function">
      <type>consteval auto</type>
      <name>kumi::make_indexes</name>
      <anchorfile>group__utility_gadba148c334bcf52088dc64992c270fdd.html</anchorfile>
      <anchor>gadba148c334bcf52088dc64992c270fdd</anchor>
      <arglist>() noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::literals::operator&quot;&quot;_c</name>
      <anchorfile>group__utility_ga60825dffaa5ee2c50e1d1a24057bdcf1.html</anchorfile>
      <anchor>ga60825dffaa5ee2c50e1d1a24057bdcf1</anchor>
      <arglist>() noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::literals::operator&quot;&quot;_id</name>
      <anchorfile>group__utility_ga10f2338fc8867a50a4295325873f3de4.html</anchorfile>
      <anchor>ga10f2338fc8867a50a4295325873f3de4</anchor>
      <arglist>() noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::literals::operator&quot;&quot;_l</name>
      <anchorfile>group__utility_ga1eb529eb7ccadf0b5e632c132c2b9750.html</anchorfile>
      <anchor>ga1eb529eb7ccadf0b5e632c132c2b9750</anchor>
      <arglist>() noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::predicate</name>
      <anchorfile>group__utility_ga9c8c29e8a2f4f5e8a663200559fdc983.html</anchorfile>
      <anchor>ga9c8c29e8a2f4f5e8a663200559fdc983</anchor>
      <arglist>() noexcept</arglist>
    </member>
    <member kind="function">
      <type>KUMI_CUDA</type>
      <name>kumi::projection_map</name>
      <anchorfile>group__utility_ga8b7f4e6ed1e7071d7c152c9870709fcb.html</anchorfile>
      <anchor>ga8b7f4e6ed1e7071d7c152c9870709fcb</anchor>
      <arglist>(Ts...) -&gt; projection_map&lt; Ts</arglist>
    </member>
    <member kind="function">
      <type>kumi::str constexpr</type>
      <name>to_str</name>
      <anchorfile>group__utility_gaf4584fa9d1d39f32081265df16e00364.html</anchorfile>
      <anchor>gaf4584fa9d1d39f32081265df16e00364</anchor>
      <arglist>(auto e)</arglist>
    </member>
    <member kind="friend">
      <type>friend std::basic_ostream&lt; CharT, Traits &gt; &amp;</type>
      <name>kumi::field::operator&lt;&lt;</name>
      <anchorfile>group__utility.html</anchorfile>
      <anchor>ga34969da06ac58348bc220ebf522233f1</anchor>
      <arglist>(std::basic_ostream&lt; CharT, Traits &gt; &amp;os, field const &amp;w) noexcept</arglist>
    </member>
    <member kind="friend">
      <type>friend std::basic_ostream&lt; CharT, Traits &gt; &amp;</type>
      <name>kumi::field&lt; Id, T &gt;::operator&lt;&lt;</name>
      <anchorfile>group__utility.html</anchorfile>
      <anchor>ga34969da06ac58348bc220ebf522233f1</anchor>
      <arglist>(std::basic_ostream&lt; CharT, Traits &gt; &amp;os, field const &amp;w) noexcept</arglist>
    </member>
    <member kind="variable">
      <type>constexpr traits_check&lt; Traits &gt;</type>
      <name>kumi::if_</name>
      <anchorfile>group__utility_gacadc026868e6654e80c57432643c804a.html</anchorfile>
      <anchor>gacadc026868e6654e80c57432643c804a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr kumi::index_t&lt; N &gt; const</type>
      <name>kumi::index</name>
      <anchorfile>group__utility.html</anchorfile>
      <anchor>gaa1c76fca002e966a0a40e311ad68d841</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr kumi::label_t&lt; Label &gt;</type>
      <name>kumi::label</name>
      <anchorfile>group__utility.html</anchorfile>
      <anchor>ga1375bb29a75ab718bdb62b65ce5582b1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr kumi::unit</type>
      <name>kumi::none</name>
      <anchorfile>group__utility.html</anchorfile>
      <anchor>gae57a2a957d7c5dc2c0b3d21e0b1a98c0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr kumi::only_t&lt; T &gt;</type>
      <name>kumi::only</name>
      <anchorfile>group__utility_ga26690952147eaa66ecf74378070ee53b.html</anchorfile>
      <anchor>ga26690952147eaa66ecf74378070ee53b</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>functional</name>
    <title>Helper Types and function</title>
    <filename>group__functional.html</filename>
    <class kind="struct">kumi::function::adjacent_unicity_t</class>
    <class kind="class">kumi::function::boolean_and</class>
    <class kind="class">kumi::function::boolean_or</class>
    <class kind="class">kumi::function::boolean_xor</class>
    <class kind="struct">kumi::function::element_or</class>
    <class kind="class">kumi::function::foldable</class>
    <class kind="class">kumi::function::numeric_add</class>
    <class kind="class">kumi::function::numeric_prod</class>
    <class kind="class">kumi::function::scannable</class>
    <class kind="struct">kumi::function::select_t</class>
    <class kind="struct">kumi::function::size_or</class>
    <class kind="struct">kumi::function::unique_t</class>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::bind_back</name>
      <anchorfile>group__functional_ga02fbf71873458cc8a364a7f6efcfadf2.html</anchorfile>
      <anchor>ga02fbf71873458cc8a364a7f6efcfadf2</anchor>
      <arglist>(C &amp;&amp;c, Ts &amp;&amp;... ts) noexcept(std::is_nothrow_move_constructible_v&lt; std::decay_t&lt; C &gt; &gt; &amp;&amp;(std::is_nothrow_move_constructible_v&lt; std::decay_t&lt; Ts &gt; &gt; &amp;&amp;...))</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::bind_front</name>
      <anchorfile>group__functional_ga08c383ce2fb100dda15baf96b4e60d2f.html</anchorfile>
      <anchor>ga08c383ce2fb100dda15baf96b4e60d2f</anchor>
      <arglist>(C &amp;&amp;c, Ts &amp;&amp;... ts) noexcept(std::is_nothrow_move_constructible_v&lt; std::decay_t&lt; C &gt; &gt; &amp;&amp;(std::is_nothrow_move_constructible_v&lt; std::decay_t&lt; Ts &gt; &gt; &amp;&amp;...))</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>kumi::function::get_or</name>
      <anchorfile>group__functional_ga42064b97f063feae3d934bd111ef74ec.html</anchorfile>
      <anchor>ga42064b97f063feae3d934bd111ef74ec</anchor>
      <arglist>(T &amp;&amp;t, V &amp;&amp;v)</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>kumi::invoke</name>
      <anchorfile>group__functional_gace270cfbaa7b0d519fdf03f8225f2908.html</anchorfile>
      <anchor>gace270cfbaa7b0d519fdf03f8225f2908</anchor>
      <arglist>(C &amp;&amp;c, Ts &amp;&amp;... ts)</arglist>
    </member>
    <member kind="function">
      <type>constexpr R</type>
      <name>kumi::invoke_r</name>
      <anchorfile>group__functional_ga2ad666793ad04ea9b66c84b83f41f375.html</anchorfile>
      <anchor>ga2ad666793ad04ea9b66c84b83f41f375</anchor>
      <arglist>(C &amp;&amp;c, Ts &amp;&amp;... ts) noexcept(std::is_nothrow_invocable_r_v&lt; R, C, Ts... &gt;)</arglist>
    </member>
    <member kind="variable">
      <type>constexpr kumi::function::boolean_and</type>
      <name>kumi::function::bit_and</name>
      <anchorfile>group__functional.html</anchorfile>
      <anchor>ga1fe39b055acf816f388cbee8074e4f2c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr kumi::function::boolean_or</type>
      <name>kumi::function::bit_or</name>
      <anchorfile>group__functional.html</anchorfile>
      <anchor>gaa1b1067fcaada1da848ffdd80df9eb8c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr kumi::function::boolean_xor</type>
      <name>kumi::function::bit_xor</name>
      <anchorfile>group__functional.html</anchorfile>
      <anchor>gaf681e250bfdc1c005c864767d0c1639d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>struct kumi::function::cartesian_product_t</type>
      <name>kumi::function::cartesian_producer</name>
      <anchorfile>group__functional_ga45a45e049b5c4aa186dc3516f85098d5.html</anchorfile>
      <anchor>ga45a45e049b5c4aa186dc3516f85098d5</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>struct kumi::function::cat_t</type>
      <name>kumi::function::concatenater</name>
      <anchorfile>group__functional_ga939d953813ec961b41fc3f4f2dab22c7.html</anchorfile>
      <anchor>ga939d953813ec961b41fc3f4f2dab22c7</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>struct kumi::function::extract_t</type>
      <name>kumi::function::extractor</name>
      <anchorfile>group__functional_ga512329bc74afee8bbdac22c3e267c4c4.html</anchorfile>
      <anchor>ga512329bc74afee8bbdac22c3e267c4c4</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr kumi::function::numeric_prod</type>
      <name>kumi::function::multiplies</name>
      <anchorfile>group__functional.html</anchorfile>
      <anchor>gadcb7f72c2a20d42543aa3b38a867e6f6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr kumi::function::numeric_add</type>
      <name>kumi::function::plus</name>
      <anchorfile>group__functional.html</anchorfile>
      <anchor>gab83f5dbd77ab8618b7925c9de6adb54d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>struct kumi::function::reduce_t</type>
      <name>kumi::function::reducer</name>
      <anchorfile>group__functional_gaaefcb5d45afa90ffd9674cc3af110c2d.html</anchorfile>
      <anchor>gaaefcb5d45afa90ffd9674cc3af110c2d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>struct kumi::function::repeat_t</type>
      <name>kumi::function::repeater</name>
      <anchorfile>group__functional_ga7101480ea637b85853e7ac2621edfcd5.html</anchorfile>
      <anchor>ga7101480ea637b85853e7ac2621edfcd5</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>struct kumi::function::reverse_t</type>
      <name>kumi::function::reverser</name>
      <anchorfile>group__functional_ga050f412223903338fb77031c089298dd.html</anchorfile>
      <anchor>ga050f412223903338fb77031c089298dd</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>struct kumi::function::rotate_t</type>
      <name>kumi::function::rotater</name>
      <anchorfile>group__functional_gaea4dcbe3352e0322ca07796c54992473.html</anchorfile>
      <anchor>gaea4dcbe3352e0322ca07796c54992473</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr kumi::function::select_t</type>
      <name>kumi::function::selector</name>
      <anchorfile>group__functional.html</anchorfile>
      <anchor>ga9063c98870899aef10f0cc080e4fea51</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>struct kumi::function::shift_t</type>
      <name>kumi::function::shifter</name>
      <anchorfile>group__functional_ga030fc00e2f98f3648974d4a2c0d2ae31.html</anchorfile>
      <anchor>ga030fc00e2f98f3648974d4a2c0d2ae31</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>struct kumi::function::slice_t</type>
      <name>kumi::function::slicer</name>
      <anchorfile>group__functional_ga3201caae7402c136e332d664a439913e.html</anchorfile>
      <anchor>ga3201caae7402c136e332d664a439913e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>struct kumi::function::split_t</type>
      <name>kumi::function::splitter</name>
      <anchorfile>group__functional_gae7fa4a3e9b7b6fd79f177f6126bcef2b.html</anchorfile>
      <anchor>gae7fa4a3e9b7b6fd79f177f6126bcef2b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>struct kumi::function::tile_t</type>
      <name>kumi::function::tiler</name>
      <anchorfile>group__functional_gaed8fd6fecbe985d0a7be0735ea44b79f.html</anchorfile>
      <anchor>gaed8fd6fecbe985d0a7be0735ea44b79f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr kumi::function::adjacent_unicity_t</type>
      <name>kumi::function::uniqued</name>
      <anchorfile>group__functional.html</anchorfile>
      <anchor>ga011bc82908c9e504b2cbffc2767251be</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr kumi::function::unique_t</type>
      <name>kumi::function::uniquer</name>
      <anchorfile>group__functional.html</anchorfile>
      <anchor>gab9c4d3ea483d68225e3a2783586c4847</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>struct kumi::function::zip_t</type>
      <name>kumi::function::zipper</name>
      <anchorfile>group__functional_gab92c8e53f4f94e60747f4bc0d5301de2.html</anchorfile>
      <anchor>gab92c8e53f4f94e60747f4bc0d5301de2</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>types</name>
    <title>Kumi Types</title>
    <filename>group__types.html</filename>
    <class kind="class">kumi::as</class>
    <class kind="class">kumi::field</class>
    <class kind="class">kumi::identifier</class>
    <class kind="class">kumi::index_t</class>
    <class kind="class">kumi::label_t</class>
    <class kind="class">kumi::name</class>
    <class kind="class">kumi::str</class>
    <class kind="class">kumi::unit</class>
    <class kind="class">kumi::unknown</class>
  </compound>
  <compound kind="group">
    <name>algorithm</name>
    <title>Product Type Algorithms</title>
    <filename>group__algorithm.html</filename>
    <subgroup>reductions</subgroup>
    <subgroup>generators</subgroup>
    <subgroup>queries</subgroup>
    <subgroup>transforms</subgroup>
  </compound>
  <compound kind="group">
    <name>reductions</name>
    <title>Product Type Generalized Reductions</title>
    <filename>group__reductions.html</filename>
    <member kind="variable">
      <type>constexpr bit_and_t</type>
      <name>kumi::bit_and</name>
      <anchorfile>group__reductions_ga17c3d8bab8099c4756a8b6fb4e9d4380.html</anchorfile>
      <anchor>ga17c3d8bab8099c4756a8b6fb4e9d4380</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr bit_or_t</type>
      <name>kumi::bit_or</name>
      <anchorfile>group__reductions_ga74fa99e87e80d8bb15ea6694e381bd49.html</anchorfile>
      <anchor>ga74fa99e87e80d8bb15ea6694e381bd49</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr bit_xor_t</type>
      <name>kumi::bit_xor</name>
      <anchorfile>group__reductions_ga2797c81f32afec2f2ce4856a5155807c.html</anchorfile>
      <anchor>ga2797c81f32afec2f2ce4856a5155807c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr exclusive_scan_left_t</type>
      <name>kumi::exclusive_scan_left</name>
      <anchorfile>group__reductions_ga529950ddf6573473b2f9b7ec886c61f9.html</anchorfile>
      <anchor>ga529950ddf6573473b2f9b7ec886c61f9</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr exclusive_scan_right_t</type>
      <name>kumi::exclusive_scan_right</name>
      <anchorfile>group__reductions_gaa66bb36d76db2d7854196bc156fb35c2.html</anchorfile>
      <anchor>gaa66bb36d76db2d7854196bc156fb35c2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr fold_left_t</type>
      <name>kumi::fold_left</name>
      <anchorfile>group__reductions_gac7fc6bc4e0aff96cca71f0a64b0f2aa1.html</anchorfile>
      <anchor>gac7fc6bc4e0aff96cca71f0a64b0f2aa1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr fold_right_t</type>
      <name>kumi::fold_right</name>
      <anchorfile>group__reductions_gaee418c18e09e3b1789c23ec00681db42.html</anchorfile>
      <anchor>gaee418c18e09e3b1789c23ec00681db42</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr inclusive_scan_left_t</type>
      <name>kumi::inclusive_scan_left</name>
      <anchorfile>group__reductions_ga1389eee6fb884b34ed4957884ecd39a1.html</anchorfile>
      <anchor>ga1389eee6fb884b34ed4957884ecd39a1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr inclusive_scan_right_t</type>
      <name>kumi::inclusive_scan_right</name>
      <anchorfile>group__reductions_gab55848ee4bd1b0cc0f22015a2bac5047.html</anchorfile>
      <anchor>gab55848ee4bd1b0cc0f22015a2bac5047</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr map_reduce_t</type>
      <name>kumi::map_reduce</name>
      <anchorfile>group__reductions_ga396afbfbcefa48f06ad76a34b6f0b523.html</anchorfile>
      <anchor>ga396afbfbcefa48f06ad76a34b6f0b523</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr max_t</type>
      <name>kumi::max</name>
      <anchorfile>group__reductions_gab76e53ad197280669806cae2c0cc130c.html</anchorfile>
      <anchor>gab76e53ad197280669806cae2c0cc130c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr min_t</type>
      <name>kumi::min</name>
      <anchorfile>group__reductions_gaafd0c178628f6f756bf0d73a34e75b2f.html</anchorfile>
      <anchor>gaafd0c178628f6f756bf0d73a34e75b2f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr prod_t</type>
      <name>kumi::prod</name>
      <anchorfile>group__reductions_ga6c139ebafaebc0f7dbca2fd57aee943c.html</anchorfile>
      <anchor>ga6c139ebafaebc0f7dbca2fd57aee943c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr reduce_t</type>
      <name>kumi::reduce</name>
      <anchorfile>group__reductions_gaf7efbfa530d2396e2ed230cc03e4046e.html</anchorfile>
      <anchor>gaf7efbfa530d2396e2ed230cc03e4046e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr sum_t</type>
      <name>kumi::sum</name>
      <anchorfile>group__reductions_ga3e8b585399de360c3ab55efc2fa0ed8c.html</anchorfile>
      <anchor>ga3e8b585399de360c3ab55efc2fa0ed8c</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>generators</name>
    <title>Product Type Generators</title>
    <filename>group__generators.html</filename>
    <member kind="variable">
      <type>constexpr all_unique_t</type>
      <name>kumi::all_unique</name>
      <anchorfile>group__generators_ga71bbbe8da94919e242bd3ded80ab6776.html</anchorfile>
      <anchor>ga71bbbe8da94919e242bd3ded80ab6776</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr as_flat_ptr_t</type>
      <name>kumi::as_flat_ptr</name>
      <anchorfile>group__generators_ga6368952a2f6a506de75aa0e01569eab6.html</anchorfile>
      <anchor>ga6368952a2f6a506de75aa0e01569eab6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr cartesian_product_t</type>
      <name>kumi::cartesian_product</name>
      <anchorfile>group__generators_ga39128fad2c11b9fea55558222a87721c.html</anchorfile>
      <anchor>ga39128fad2c11b9fea55558222a87721c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr cat_t</type>
      <name>kumi::cat</name>
      <anchorfile>group__generators_ga4550222df58187f71b1b1347500e324a.html</anchorfile>
      <anchor>ga4550222df58187f71b1b1347500e324a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr tiles_t&lt; N, N &gt;</type>
      <name>kumi::chunks</name>
      <anchorfile>group__generators_gaf4b0bcda72790c2ac55519adaf89456e.html</anchorfile>
      <anchor>gaf4b0bcda72790c2ac55519adaf89456e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr compress_t</type>
      <name>kumi::compress</name>
      <anchorfile>group__generators_gaa9d6196838118af0a837160d8bbf532c.html</anchorfile>
      <anchor>gaa9d6196838118af0a837160d8bbf532c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr extract_t</type>
      <name>kumi::extract</name>
      <anchorfile>group__generators_ga1a7617bafd6f8598cca8e7e6a5c6f383.html</anchorfile>
      <anchor>ga1a7617bafd6f8598cca8e7e6a5c6f383</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr fill_t&lt; N &gt;</type>
      <name>kumi::fill</name>
      <anchorfile>group__generators_gafd5d1c6d3d2fcb3c424826b8bddb8b0a.html</anchorfile>
      <anchor>gafd5d1c6d3d2fcb3c424826b8bddb8b0a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr filter_t&lt; Pred &gt;</type>
      <name>kumi::filter</name>
      <anchorfile>group__generators_ga2c9b5ff6b698c7dcb0feb2da1679fa9b.html</anchorfile>
      <anchor>ga2c9b5ff6b698c7dcb0feb2da1679fa9b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr filter_not_t&lt; Pred &gt;</type>
      <name>kumi::filter_not</name>
      <anchorfile>group__generators_ga750bc3d3425c955e1be6ef1b3879c314.html</anchorfile>
      <anchor>ga750bc3d3425c955e1be6ef1b3879c314</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr flatten_t</type>
      <name>kumi::flatten</name>
      <anchorfile>group__generators_ga49acccc42ec8af7b96b63e8f38796df2.html</anchorfile>
      <anchor>ga49acccc42ec8af7b96b63e8f38796df2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr flatten_all_t</type>
      <name>kumi::flatten_all</name>
      <anchorfile>group__generators_gaa780fd338fb61c86f226ae05adfaf426.html</anchorfile>
      <anchor>gaa780fd338fb61c86f226ae05adfaf426</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr generate_t&lt; N &gt;</type>
      <name>kumi::generate</name>
      <anchorfile>group__generators_gaba2efbda8df6baaccd4e35343d70163f.html</anchorfile>
      <anchor>gaba2efbda8df6baaccd4e35343d70163f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr iota_t&lt; N &gt;</type>
      <name>kumi::iota</name>
      <anchorfile>group__generators_gace6e022bb94a706731299b9d395ac10d.html</anchorfile>
      <anchor>gace6e022bb94a706731299b9d395ac10d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr member_cast_t&lt; T &gt;</type>
      <name>kumi::member_cast</name>
      <anchorfile>group__generators_gad2e4009d5d28df5090885b030f08f1f8.html</anchorfile>
      <anchor>gad2e4009d5d28df5090885b030f08f1f8</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr partition_t&lt; Pred &gt;</type>
      <name>kumi::partition</name>
      <anchorfile>group__generators_ga4643116b2dc0dfbd0d15fee408a9c18c.html</anchorfile>
      <anchor>ga4643116b2dc0dfbd0d15fee408a9c18c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr pop_front_t</type>
      <name>kumi::pop_front</name>
      <anchorfile>group__generators_ga38d1ddeb5090405e79e9b7d898a85133.html</anchorfile>
      <anchor>ga38d1ddeb5090405e79e9b7d898a85133</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr push_front_t</type>
      <name>kumi::push_front</name>
      <anchorfile>group__generators_gad4bd53f162f63af0cbfbd68d8adb5d5c.html</anchorfile>
      <anchor>gad4bd53f162f63af0cbfbd68d8adb5d5c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr reindex_t&lt; Projections &gt;</type>
      <name>kumi::reindex</name>
      <anchorfile>group__generators_ga3594f15dbfba2f6fda0afc8d1542c449.html</anchorfile>
      <anchor>ga3594f15dbfba2f6fda0afc8d1542c449</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr remove_t</type>
      <name>kumi::remove</name>
      <anchorfile>group__generators_ga0f52ba0b24ce54052784df91c54ac233.html</anchorfile>
      <anchor>ga0f52ba0b24ce54052784df91c54ac233</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr reorder_t&lt; I... &gt;</type>
      <name>kumi::reorder</name>
      <anchorfile>group__generators_ga32af967d7f453426ccd564d3a0b6c689.html</anchorfile>
      <anchor>ga32af967d7f453426ccd564d3a0b6c689</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr reorder_fields_t&lt; Name... &gt;</type>
      <name>kumi::reorder_fields</name>
      <anchorfile>group__generators_ga8c42552c8f93dad0b83a3903468d02c6.html</anchorfile>
      <anchor>ga8c42552c8f93dad0b83a3903468d02c6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr rotate_left_t&lt; R &gt;</type>
      <name>kumi::rotate_left</name>
      <anchorfile>group__generators_gadbc56977f82e2eaefe486c0a9457f01c.html</anchorfile>
      <anchor>gadbc56977f82e2eaefe486c0a9457f01c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr rotate_right_t&lt; R &gt;</type>
      <name>kumi::rotate_right</name>
      <anchorfile>group__generators_gaffd5dbb36e1c70d2fc058ffe03afef3e.html</anchorfile>
      <anchor>gaffd5dbb36e1c70d2fc058ffe03afef3e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr split_t</type>
      <name>kumi::split</name>
      <anchorfile>group__generators_gadb81f4533e81830674c3fc9577d3de93.html</anchorfile>
      <anchor>gadb81f4533e81830674c3fc9577d3de93</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr tiles_t&lt; N, O &gt;</type>
      <name>kumi::tiles</name>
      <anchorfile>group__generators_ga3d1b4a8309328d854d7b6234fde3aeb0.html</anchorfile>
      <anchor>ga3d1b4a8309328d854d7b6234fde3aeb0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr transpose_t</type>
      <name>kumi::transpose</name>
      <anchorfile>group__generators_gaef527bdd76c70e7fded23a9759428f5c.html</anchorfile>
      <anchor>gaef527bdd76c70e7fded23a9759428f5c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr unique_t</type>
      <name>kumi::unique</name>
      <anchorfile>group__generators_ga6479cba59ee95d4a0779e94993ab55a9.html</anchorfile>
      <anchor>ga6479cba59ee95d4a0779e94993ab55a9</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr tiles_t&lt; N, 1 &gt;</type>
      <name>kumi::windows</name>
      <anchorfile>group__generators_gade96292292ae11da69415a778ef45ad0.html</anchorfile>
      <anchor>gade96292292ae11da69415a778ef45ad0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr zip_t</type>
      <name>kumi::zip</name>
      <anchorfile>group__generators_ga71c21174289ba175a8d3d4b170cec05f.html</anchorfile>
      <anchor>ga71c21174289ba175a8d3d4b170cec05f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr zip_max_t</type>
      <name>kumi::zip_max</name>
      <anchorfile>group__generators_ga0ce4823febfb00cfb197f73332ba7309.html</anchorfile>
      <anchor>ga0ce4823febfb00cfb197f73332ba7309</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr zip_min_t</type>
      <name>kumi::zip_min</name>
      <anchorfile>group__generators_gaf4b9aea3cee7c30fc6a516c632805423.html</anchorfile>
      <anchor>gaf4b9aea3cee7c30fc6a516c632805423</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>queries</name>
    <title>Product Type Queries</title>
    <filename>group__queries.html</filename>
    <member kind="variable">
      <type>constexpr all_of_t</type>
      <name>kumi::all_of</name>
      <anchorfile>group__queries_gaffdb8063b72f079107cd8a7e293ba298.html</anchorfile>
      <anchor>gaffdb8063b72f079107cd8a7e293ba298</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr any_of_t</type>
      <name>kumi::any_of</name>
      <anchorfile>group__queries_ga79566892f932a2308e23b5f21b95086f.html</anchorfile>
      <anchor>ga79566892f932a2308e23b5f21b95086f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr back_t</type>
      <name>kumi::back</name>
      <anchorfile>group__queries_gae635e0c094282372ff5393840b6f52c2.html</anchorfile>
      <anchor>gae635e0c094282372ff5393840b6f52c2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr contains_t</type>
      <name>kumi::contains</name>
      <anchorfile>group__queries_ga3a9b6e2d0fbdace9e57b3846d24a3b57.html</anchorfile>
      <anchor>ga3a9b6e2d0fbdace9e57b3846d24a3b57</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr contains_any_t</type>
      <name>kumi::contains_any</name>
      <anchorfile>group__queries_ga639f59cb294f670d2f2c468c4ef204d3.html</anchorfile>
      <anchor>ga639f59cb294f670d2f2c468c4ef204d3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr contains_none_t</type>
      <name>kumi::contains_none</name>
      <anchorfile>group__queries_ga7b1bbe80c513abfdedd1196f027601d2.html</anchorfile>
      <anchor>ga7b1bbe80c513abfdedd1196f027601d2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr contains_only_t</type>
      <name>kumi::contains_only</name>
      <anchorfile>group__queries_ga36431211bf121466392b290459a45498.html</anchorfile>
      <anchor>ga36431211bf121466392b290459a45498</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr count_t</type>
      <name>kumi::count</name>
      <anchorfile>group__queries_ga8240f113b5feb1dcc826949f28f17a47.html</anchorfile>
      <anchor>ga8240f113b5feb1dcc826949f28f17a47</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr count_if_t</type>
      <name>kumi::count_if</name>
      <anchorfile>group__queries_gaec0fb27dc2250b97648bc52b8e83b561.html</anchorfile>
      <anchor>gaec0fb27dc2250b97648bc52b8e83b561</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr front_t</type>
      <name>kumi::front</name>
      <anchorfile>group__queries_gaa1618c96c4c7003afeccfb19e25b35bb.html</anchorfile>
      <anchor>gaa1618c96c4c7003afeccfb19e25b35bb</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr locate_t</type>
      <name>kumi::locate</name>
      <anchorfile>group__queries_ga39f807d6c2b8909a712d431acde4153e.html</anchorfile>
      <anchor>ga39f807d6c2b8909a712d431acde4153e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr none_of_t</type>
      <name>kumi::none_of</name>
      <anchorfile>group__queries_ga26e030c97733248f67dd2c8fbf527602.html</anchorfile>
      <anchor>ga26e030c97733248f67dd2c8fbf527602</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>concepts</name>
    <title>Product Type Related Concepts</title>
    <filename>group__concepts.html</filename>
    <concept>kumi::concepts::compatible_product_types</concept>
    <concept>kumi::concepts::container</concept>
    <concept>kumi::concepts::contains_identifier</concept>
    <concept>kumi::concepts::contains_label</concept>
    <concept>kumi::concepts::contains_type</concept>
    <concept>kumi::concepts::empty_product_type</concept>
    <concept>kumi::concepts::equality_comparable</concept>
    <concept>kumi::concepts::equivalent</concept>
    <concept>kumi::concepts::field</concept>
    <concept>kumi::concepts::follows_same_semantic</concept>
    <concept>kumi::concepts::fully_named</concept>
    <concept>kumi::concepts::has_named_fields</concept>
    <concept>kumi::concepts::homogeneous_product_type</concept>
    <concept>kumi::concepts::identifier</concept>
    <concept>kumi::concepts::monoid</concept>
    <concept>kumi::concepts::non_empty_product_type</concept>
    <concept>kumi::concepts::product_type</concept>
    <concept>kumi::concepts::projection</concept>
    <concept>kumi::concepts::projection_map</concept>
    <concept>kumi::concepts::queryable_by_identifier</concept>
    <concept>kumi::concepts::queryable_by_label</concept>
    <concept>kumi::concepts::record_type</concept>
    <concept>kumi::concepts::sized_product_type</concept>
    <concept>kumi::concepts::sized_product_type_or_more</concept>
    <concept>kumi::concepts::static_container</concept>
    <concept>kumi::concepts::uniquely_labeled</concept>
    <concept>kumi::concepts::uniquely_named</concept>
    <concept>kumi::concepts::uniquely_typed</concept>
    <concept>kumi::concepts::unit_type</concept>
    <member kind="function">
      <type>consteval auto</type>
      <name>kumi::concepts::can_query</name>
      <anchorfile>group__concepts_gab33a99db2d26f6e84fec5384c4e36491.html</anchorfile>
      <anchor>gab33a99db2d26f6e84fec5384c4e36491</anchor>
      <arglist>()</arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>traits</name>
    <title>Product Type Related Traits</title>
    <filename>group__traits.html</filename>
    <subgroup>record_traits</subgroup>
    <subgroup>tuple_traits</subgroup>
    <class kind="struct">kumi::all_unique_names</class>
    <class kind="struct">kumi::all_uniques</class>
    <class kind="struct">kumi::apply_traits</class>
    <class kind="struct">kumi::common_product_type</class>
    <class kind="struct">kumi::container_size</class>
    <class kind="struct">kumi::container_type</class>
    <class kind="struct">kumi::element</class>
    <class kind="struct">kumi::has_static_size</class>
    <class kind="struct">kumi::is_container</class>
    <class kind="struct">kumi::is_equality_comparable</class>
    <class kind="struct">kumi::is_equivalent</class>
    <class kind="struct">kumi::is_product_type</class>
    <class kind="struct">kumi::is_projection_map</class>
    <class kind="struct">kumi::is_record_type</class>
    <class kind="struct">kumi::map_traits</class>
    <class kind="struct">kumi::member</class>
    <class kind="struct">kumi::size</class>
    <class kind="struct">kumi::stored_member</class>
  </compound>
  <compound kind="group">
    <name>transforms</name>
    <title>Product Type Transformations</title>
    <filename>group__transforms.html</filename>
    <subgroup>record_transforms</subgroup>
    <subgroup>tuple_transforms</subgroup>
    <member kind="variable">
      <type>constexpr apply_t</type>
      <name>kumi::apply</name>
      <anchorfile>group__transforms_ga4c69a49971100b7bc9c7effd7c43f191.html</anchorfile>
      <anchor>ga4c69a49971100b7bc9c7effd7c43f191</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr apply_field_t</type>
      <name>kumi::apply_field</name>
      <anchorfile>group__transforms_ga992364930a4a5a5b64b26730773536ab.html</anchorfile>
      <anchor>ga992364930a4a5a5b64b26730773536ab</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr for_each_t</type>
      <name>kumi::for_each</name>
      <anchorfile>group__transforms_ga58c4bb5e62083b4b37396d39c6446164.html</anchorfile>
      <anchor>ga58c4bb5e62083b4b37396d39c6446164</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr map_t</type>
      <name>kumi::map</name>
      <anchorfile>group__transforms_gaeaba737291ba1085d77272eae38a016e.html</anchorfile>
      <anchor>gaeaba737291ba1085d77272eae38a016e</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>tuple_related</name>
    <title>Product Types and associated Functions</title>
    <filename>group__tuple__related.html</filename>
    <class kind="struct">kumi::as_tuple</class>
    <class kind="class">kumi::tuple</class>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::tie</name>
      <anchorfile>group__tuple__related_ga834fa03c64e67b8bdebccec00e9d195b.html</anchorfile>
      <anchor>ga834fa03c64e67b8bdebccec00e9d195b</anchor>
      <arglist>(Ts &amp;... ts) -&gt; kumi::tuple&lt; Ts &amp;... &gt;</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::forward_as_tuple</name>
      <anchorfile>group__tuple__related_gac167a1000c9c61798b7d8c684f3c804b.html</anchorfile>
      <anchor>gac167a1000c9c61798b7d8c684f3c804b</anchor>
      <arglist>(Ts &amp;&amp;... ts) -&gt; kumi::tuple&lt; Ts &amp;&amp;... &gt;</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::make_tuple</name>
      <anchorfile>group__tuple__related_ga8570ddb839f6b158633537fd7113e795.html</anchorfile>
      <anchor>ga8570ddb839f6b158633537fd7113e795</anchor>
      <arglist>(Ts &amp;&amp;... ts) -&gt; kumi::tuple&lt; std::unwrap_ref_decay_t&lt; Ts &gt;... &gt;</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::to_ref</name>
      <anchorfile>group__tuple__related_ga727f8ab64140ca60bcb1c8aded343c0b.html</anchorfile>
      <anchor>ga727f8ab64140ca60bcb1c8aded343c0b</anchor>
      <arglist>(T &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::from_tuple</name>
      <anchorfile>group__tuple__related_ga81cca523672d8799bbe35fa4f07dd61f.html</anchorfile>
      <anchor>ga81cca523672d8799bbe35fa4f07dd61f</anchor>
      <arglist>(tuple&lt; Ts... &gt; const &amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::to_tuple</name>
      <anchorfile>group__tuple__related_ga0bacdab2d5c18c44431ba8f74b86a5f0.html</anchorfile>
      <anchor>ga0bacdab2d5c18c44431ba8f74b86a5f0</anchor>
      <arglist>(T &amp;&amp;t)</arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>record_traits</name>
    <title>Record Related Traits</title>
    <filename>group__record__traits.html</filename>
    <class kind="struct">kumi::stored_element</class>
  </compound>
  <compound kind="group">
    <name>record_transforms</name>
    <title>Record Type Specific Transformations</title>
    <filename>group__record__transforms.html</filename>
    <member kind="variable">
      <type>constexpr map_field_t</type>
      <name>kumi::map_field</name>
      <anchorfile>group__record__transforms_gafe68ca583e3e822b20f60ff35e5aa9d3.html</anchorfile>
      <anchor>gafe68ca583e3e822b20f60ff35e5aa9d3</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>record_related</name>
    <title>Record Types and associated Functions</title>
    <filename>group__record__related.html</filename>
    <class kind="class">kumi::record</class>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::tie</name>
      <anchorfile>group__record__related_ga9d6e39a733f56863dfa21cb1f07fdc3a.html</anchorfile>
      <anchor>ga9d6e39a733f56863dfa21cb1f07fdc3a</anchor>
      <arglist>(Ts &amp;... ts) -&gt; kumi::record&lt; kumi::field&lt; decltype(Fields), Ts &amp; &gt;... &gt; requires(sizeof...(Fields)==sizeof...(Ts))</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::forward_as_record</name>
      <anchorfile>group__record__related_gaa0d291bc5523e9e07e5c38559e0dcb3d.html</anchorfile>
      <anchor>gaa0d291bc5523e9e07e5c38559e0dcb3d</anchor>
      <arglist>(Ts &amp;&amp;... ts) -&gt; kumi::record&lt; kumi::field&lt; decltype(Fields), Ts &amp;&amp; &gt;... &gt; requires(sizeof...(Fields)==sizeof...(Ts))</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::make_record</name>
      <anchorfile>group__record__related_ga96da0243ca4cf9e490f62c327f51fe4e.html</anchorfile>
      <anchor>ga96da0243ca4cf9e490f62c327f51fe4e</anchor>
      <arglist>(Ts &amp;&amp;... ts) -&gt; kumi::record&lt; std::unwrap_ref_decay_t&lt; Ts &gt;... &gt; requires(kumi::concepts::uniquely_named&lt; Ts... &gt; &amp;&amp;kumi::concepts::fully_named&lt; Ts... &gt;)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::to_ref</name>
      <anchorfile>group__record__related_ga83a97fc306d9ecfacde28584b219b44a.html</anchorfile>
      <anchor>ga83a97fc306d9ecfacde28584b219b44a</anchor>
      <arglist>(R &amp;&amp;r)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::from_record</name>
      <anchorfile>group__record__related_ga772ac1518ac3bbe1627db9c00f56abdd.html</anchorfile>
      <anchor>ga772ac1518ac3bbe1627db9c00f56abdd</anchor>
      <arglist>(record&lt; Ts... &gt; const &amp;r)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::to_record</name>
      <anchorfile>group__record__related_ga324cc6775ad5b15767fc2eaae02abd73.html</anchorfile>
      <anchor>ga324cc6775ad5b15767fc2eaae02abd73</anchor>
      <arglist>(Type &amp;&amp;r)</arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>tuple_traits</name>
    <title>Tuple Related Traits</title>
    <filename>group__tuple__traits.html</filename>
    <class kind="struct">kumi::is_homogeneous</class>
  </compound>
  <compound kind="group">
    <name>tuple_transforms</name>
    <title>Tuple Type Specific Transformations</title>
    <filename>group__tuple__transforms.html</filename>
    <member kind="variable">
      <type>constexpr map_index_t</type>
      <name>kumi::map_index</name>
      <anchorfile>group__tuple__transforms_ga64a8c36072828fb7b724ba0ab8fc59bc.html</anchorfile>
      <anchor>ga64a8c36072828fb7b724ba0ab8fc59bc</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="page">
    <name>changelog</name>
    <title>Change Log</title>
    <filename>changelog.html</filename>
    <docanchor file="changelog.html" title="/__w/kumi/kumi/doc/changelog.md">md__2____w_2kumi_2kumi_2doc_2changelog</docanchor>
  </compound>
  <compound kind="page">
    <name>cpp_spec</name>
    <title>C++ Specific Terms</title>
    <filename>cpp_spec.html</filename>
    <docanchor file="cpp_spec.html" title="/__w/kumi/kumi/doc/glossary/cpp_vocabulary.md">md__2____w_2kumi_2kumi_2doc_2glossary_2cpp__vocabulary</docanchor>
  </compound>
  <compound kind="page">
    <name>identity</name>
    <title>The Identity Elements (The &quot;0&quot; and &quot;1&quot; of Types)</title>
    <filename>identity.html</filename>
    <docanchor file="identity.html" title="Empty Type :  \_form#0">empty</docanchor>
    <docanchor file="identity.html" title="Unit Type :  \_form#3">unit</docanchor>
  </compound>
  <compound kind="page">
    <name>introduction</name>
    <title>Type Theoretic Foundations</title>
    <filename>introduction.html</filename>
    <docanchor file="introduction.html" title="Origin">origin</docanchor>
    <docanchor file="introduction.html" title="The Curry-Howard Correspondence">curry_howard</docanchor>
    <docanchor file="introduction.html" title="Fundamentals">fundamentals</docanchor>
    <docanchor file="introduction.html" title="Type Cardinality">cardinality</docanchor>
  </compound>
  <compound kind="page">
    <name>nomenclature</name>
    <title>Nomenclature</title>
    <filename>nomenclature.html</filename>
  </compound>
  <compound kind="page">
    <name>product</name>
    <title>Product Types</title>
    <filename>product.html</filename>
    <docanchor file="product.html" title="Product Constructions (The Logic of &quot;AND&quot;)">product_construction</docanchor>
    <docanchor file="product.html" title="Product Type  \_form#27">product_type</docanchor>
    <docanchor file="product.html" title="Programming Languages Considerations">tuple_programming</docanchor>
    <docanchor file="product.html" title="Record Type  \_form#38">record_type</docanchor>
  </compound>
  <compound kind="page">
    <name>licence</name>
    <title>Licence</title>
    <filename>licence.html</filename>
    <docanchor file="licence.html" title="/__w/kumi/kumi/doc/licence.md">md__2____w_2kumi_2kumi_2doc_2licence</docanchor>
  </compound>
  <compound kind="page">
    <name>setup</name>
    <title>Setup</title>
    <filename>setup.html</filename>
    <docanchor file="setup.html" title="Pre-requisites">prerequisit</docanchor>
    <docanchor file="setup.html" title="Install from the source">setup-source</docanchor>
    <docanchor file="setup.html" title="Standalone setup">setup-standalone</docanchor>
    <docanchor file="setup.html" title="CMake FetchContent">setup-fetchcontent</docanchor>
    <docanchor file="setup.html" title="Setup with CPM">setup-cpm</docanchor>
  </compound>
  <compound kind="page">
    <name>index</name>
    <title>The C++20 Compact Tuple Tools</title>
    <filename>index.html</filename>
  </compound>
</tagfile>
