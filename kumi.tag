<?xml version='1.0' encoding='UTF-8' standalone='yes' ?>
<tagfile doxygen_version="1.16.1" doxygen_gitid="669aeeefca743c148e2d935b3d3c69535c7491e6">
  <compound kind="struct">
    <name>kumi::function::adjacent_unicity_t</name>
    <filename>structkumi_1_1function_1_1adjacent__unicity__t.html</filename>
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
    <name>kumi::as_tuple</name>
    <filename>structkumi_1_1as__tuple.html</filename>
    <templarg>typename T</templarg>
    <templarg>template&lt; typename... &gt; class Meta</templarg>
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
    <name>kumi::function::cartesian_product_t</name>
    <filename>structkumi_1_1function_1_1cartesian__product__t.html</filename>
  </compound>
  <compound kind="struct">
    <name>kumi::function::cat_t</name>
    <filename>structkumi_1_1function_1_1cat__t.html</filename>
  </compound>
  <compound kind="struct">
    <name>kumi::common_product_type</name>
    <filename>structkumi_1_1common__product__type.html</filename>
    <templarg>typename... Ts</templarg>
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
      <anchor>a63367163ac0f0e4920f6eb18b2b2129e</anchor>
      <arglist>() noexcept</arglist>
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
      <anchor>a5c52e3942bf6c89c3300d8cdb9b60b43</anchor>
      <arglist>(identifier&lt; ID, Checker &gt; const &amp;)</arglist>
    </member>
    <member kind="friend">
      <type>friend std::basic_ostream&lt; CharT, Traits &gt; &amp;</type>
      <name>operator&lt;&lt;</name>
      <anchorfile>structkumi_1_1identifier.html</anchorfile>
      <anchor>a40e31b641532e8be5a14ed126dc9b1d9</anchor>
      <arglist>(std::basic_ostream&lt; CharT, Traits &gt; &amp;os, identifier const &amp;id) noexcept</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>kumi::index_t</name>
    <filename>structkumi_1_1index__t.html</filename>
    <templarg>std::size_t N</templarg>
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
    <name>kumi::map_traits</name>
    <filename>structkumi_1_1map__traits.html</filename>
    <templarg>template&lt; typename... &gt; typename Traits</templarg>
    <templarg>typename T</templarg>
    <templarg>typename Seq</templarg>
  </compound>
  <compound kind="struct">
    <name>kumi::member</name>
    <filename>structkumi_1_1member.html</filename>
    <templarg>std::size_t I</templarg>
    <templarg>typename T</templarg>
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
      <anchor>a2394e49b42ad16dd1e3001e36c31a7e5</anchor>
      <arglist>(name&lt; ID &gt; const &amp;)</arglist>
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
    <name>kumi::function::reduce_t</name>
    <filename>structkumi_1_1function_1_1reduce__t.html</filename>
  </compound>
  <compound kind="struct">
    <name>kumi::function::rotate_t</name>
    <filename>structkumi_1_1function_1_1rotate__t.html</filename>
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
    <name>kumi::function::split_t</name>
    <filename>structkumi_1_1function_1_1split__t.html</filename>
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
    <name>kumi::function::tile_t</name>
    <filename>structkumi_1_1function_1_1tile__t.html</filename>
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
      <type></type>
      <name>explicit</name>
      <anchorfile>structkumi_1_1tuple_aaa14c34539f5fc51720d14b1786ee4ff.html</anchorfile>
      <anchor>aaa14c34539f5fc51720d14b1786ee4ff</anchor>
      <arglist>(!kumi_implementation_defined) const expr operator tuple&lt; Us... &gt;() const</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>explicit</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>a770e14754cd7005c314c707eab25fa42</anchor>
      <arglist>(!kumi_implementation_defined) const expr operator tuple&lt; Us... &gt;()</arglist>
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
    <name>kumi::function::zip_t</name>
    <filename>structkumi_1_1function_1_1zip__t.html</filename>
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
    <name>kumi::concepts::queryable_by_type</name>
    <filename>conceptkumi_1_1concepts_1_1queryable__by__type.html</filename>
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
      <name>all_of</name>
      <anchorfile>group__queries_ga599b0ea5293a040316abedd19bb72f42.html</anchorfile>
      <anchor>ga599b0ea5293a040316abedd19bb72f42</anchor>
      <arglist>(T &amp;&amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>all_of</name>
      <anchorfile>group__queries_ga72fb1b09abe23dbd9c6f2783c98c0c5d.html</anchorfile>
      <anchor>ga72fb1b09abe23dbd9c6f2783c98c0c5d</anchor>
      <arglist>(T &amp;&amp;t, Pred p) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>all_unique</name>
      <anchorfile>group__generators_gacf670e19ac40c8981f52ad0783a3e483.html</anchorfile>
      <anchor>gacf670e19ac40c8981f52ad0783a3e483</anchor>
      <arglist>(T &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>any_of</name>
      <anchorfile>group__queries_ga372b7bd18ab6b59234a6c68d74d298cf.html</anchorfile>
      <anchor>ga372b7bd18ab6b59234a6c68d74d298cf</anchor>
      <arglist>(T &amp;&amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>any_of</name>
      <anchorfile>group__queries_ga77b8923d8b86a504f8b683d16a9f1c3b.html</anchorfile>
      <anchor>ga77b8923d8b86a504f8b683d16a9f1c3b</anchor>
      <arglist>(T &amp;&amp;t, Pred p) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>apply</name>
      <anchorfile>group__transforms_ga9982fadb19cb52094d6165bca7f57f25.html</anchorfile>
      <anchor>ga9982fadb19cb52094d6165bca7f57f25</anchor>
      <arglist>(Function &amp;&amp;f, T &amp;&amp;t) noexcept(kumi_implementation_defined)</arglist>
    </member>
    <member kind="function">
      <type>auto</type>
      <name>as_flat_ptr</name>
      <anchorfile>group__generators_ga418f0a47f05b67dbb354d274dee63e4e.html</anchorfile>
      <anchor>ga418f0a47f05b67dbb354d274dee63e4e</anchor>
      <arglist>(T &amp;&amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>back</name>
      <anchorfile>group__generators_gacbfca9b5e95948e4180a54e920d19c6f.html</anchorfile>
      <anchor>gacbfca9b5e95948e4180a54e920d19c6f</anchor>
      <arglist>(T &amp;&amp;t)</arglist>
    </member>
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
      <type>constexpr auto</type>
      <name>bit_and</name>
      <anchorfile>group__reductions_ga2249743d977a87399b3fd98b0cb2e55e.html</anchorfile>
      <anchor>ga2249743d977a87399b3fd98b0cb2e55e</anchor>
      <arglist>(T &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>bit_and</name>
      <anchorfile>group__reductions_ga14432e4394da47b90f34c962979da853.html</anchorfile>
      <anchor>ga14432e4394da47b90f34c962979da853</anchor>
      <arglist>(T &amp;&amp;t, Value init)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>bit_or</name>
      <anchorfile>group__reductions_gaa7d3ae229843ffb2bbcabb1427ef4979.html</anchorfile>
      <anchor>gaa7d3ae229843ffb2bbcabb1427ef4979</anchor>
      <arglist>(T &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>bit_or</name>
      <anchorfile>group__reductions_ga4b48b6259301405bba1e0944ffa6e2c7.html</anchorfile>
      <anchor>ga4b48b6259301405bba1e0944ffa6e2c7</anchor>
      <arglist>(T &amp;&amp;t, Value init)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>bit_xor</name>
      <anchorfile>group__reductions_ga19a1070aa59a1fd90bbf39b860058f9d.html</anchorfile>
      <anchor>ga19a1070aa59a1fd90bbf39b860058f9d</anchor>
      <arglist>(T &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>bit_xor</name>
      <anchorfile>group__reductions_ga521dcc4de231768115582401a1a0419b.html</anchorfile>
      <anchor>ga521dcc4de231768115582401a1a0419b</anchor>
      <arglist>(T &amp;&amp;t, Value init)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>cartesian_product</name>
      <anchorfile>group__generators_ga461b0473347a35c07e54f9b3d324ad94.html</anchorfile>
      <anchor>ga461b0473347a35c07e54f9b3d324ad94</anchor>
      <arglist>(Ts &amp;&amp;... ts)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>cat</name>
      <anchorfile>group__generators_ga54c98adccbd7a86240d50e915d789650.html</anchorfile>
      <anchor>ga54c98adccbd7a86240d50e915d789650</anchor>
      <arglist>(Ts &amp;&amp;... ts)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>chunks</name>
      <anchorfile>group__generators_ga3cb72901ec2c82a9b4d4ff5bf513237c.html</anchorfile>
      <anchor>ga3cb72901ec2c82a9b4d4ff5bf513237c</anchor>
      <arglist>(T &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>contains</name>
      <anchorfile>group__queries_ga5b1e2b6241cc570b3688866e8f729d63.html</anchorfile>
      <anchor>ga5b1e2b6241cc570b3688866e8f729d63</anchor>
      <arglist>(T &amp;&amp;t, ID const &amp;id) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>contains_any</name>
      <anchorfile>group__queries_gade57a6c7c09f285d24d85343e87247ee.html</anchorfile>
      <anchor>gade57a6c7c09f285d24d85343e87247ee</anchor>
      <arglist>(T &amp;&amp;t, Is const &amp;... ids) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>contains_none</name>
      <anchorfile>group__queries_ga1fe92be51ecab233d192ad35dd56dd3d.html</anchorfile>
      <anchor>ga1fe92be51ecab233d192ad35dd56dd3d</anchor>
      <arglist>(T &amp;&amp;t, Is const &amp;... ids) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>contains_only</name>
      <anchorfile>group__queries_gaaa6ceb114c1f1ecf07428a655923ff95.html</anchorfile>
      <anchor>gaaa6ceb114c1f1ecf07428a655923ff95</anchor>
      <arglist>(T &amp;&amp;t, Is const &amp;... ids) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr std::size_t</type>
      <name>count</name>
      <anchorfile>group__queries_ga89924270e75ae69034cab01a0136b062.html</anchorfile>
      <anchor>ga89924270e75ae69034cab01a0136b062</anchor>
      <arglist>(T &amp;&amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr std::size_t</type>
      <name>count_if</name>
      <anchorfile>group__queries_ga149410b213526c378704e3dea56559ad.html</anchorfile>
      <anchor>ga149410b213526c378704e3dea56559ad</anchor>
      <arglist>(T &amp;&amp;t, Pred p) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>exclusive_scan_left</name>
      <anchorfile>group__reductions_gae113f4baf3a17cc22dac25df57c06031.html</anchorfile>
      <anchor>gae113f4baf3a17cc22dac25df57c06031</anchor>
      <arglist>(Function f, T &amp;&amp;t, Value init)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>exclusive_scan_left</name>
      <anchorfile>group__reductions_ga3cba3a0d02a465184302a59f4d05bc89.html</anchorfile>
      <anchor>ga3cba3a0d02a465184302a59f4d05bc89</anchor>
      <arglist>(M &amp;&amp;m, T &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>exclusive_scan_right</name>
      <anchorfile>group__reductions_gae9b0c7f1e3d7ecc8463c7275dfad5078.html</anchorfile>
      <anchor>gae9b0c7f1e3d7ecc8463c7275dfad5078</anchor>
      <arglist>(Function f, T &amp;&amp;t, Value init)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>exclusive_scan_right</name>
      <anchorfile>group__reductions_ga33f26f28d0909a45b8e2e62b39a8bf4e.html</anchorfile>
      <anchor>ga33f26f28d0909a45b8e2e62b39a8bf4e</anchor>
      <arglist>(M &amp;&amp;m, T &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>extract</name>
      <anchorfile>namespacekumi.html</anchorfile>
      <anchor>ae9743f017d1badce5a89351fd15e5b80</anchor>
      <arglist>(T &amp;&amp;t, kumi::index_t&lt; I0 &gt; i0) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>extract</name>
      <anchorfile>group__generators_ga40f37d0cfe5e51d7930c021eb67205bc.html</anchorfile>
      <anchor>ga40f37d0cfe5e51d7930c021eb67205bc</anchor>
      <arglist>(T &amp;&amp;t, kumi::index_t&lt; I0 &gt; i0, kumi::index_t&lt; I1 &gt; i1) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>field_value_of</name>
      <anchorfile>group__utility_gabf2013046cf8ec8ac781128a815709cc.html</anchorfile>
      <anchor>gabf2013046cf8ec8ac781128a815709cc</anchor>
      <arglist>(T &amp;&amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>fill</name>
      <anchorfile>group__generators_gac1f2b67c16429675ca7b9106793f9001.html</anchorfile>
      <anchor>gac1f2b67c16429675ca7b9106793f9001</anchor>
      <arglist>(T const &amp;v) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>filter</name>
      <anchorfile>group__generators_gaafed5030f3115f8fda5f1966a9fdfd38.html</anchorfile>
      <anchor>gaafed5030f3115f8fda5f1966a9fdfd38</anchor>
      <arglist>(T &amp;&amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>filter_not</name>
      <anchorfile>group__generators_ga4252a5ff33d90265f42d4b6c70e48bed.html</anchorfile>
      <anchor>ga4252a5ff33d90265f42d4b6c70e48bed</anchor>
      <arglist>(T &amp;&amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>flatten</name>
      <anchorfile>group__generators_ga6a021e42590689a905a2d8268c860838.html</anchorfile>
      <anchor>ga6a021e42590689a905a2d8268c860838</anchor>
      <arglist>(T &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>flatten_all</name>
      <anchorfile>namespacekumi.html</anchorfile>
      <anchor>a7fcee37f7e0ccc2adad9f91fa48fd34b</anchor>
      <arglist>(T &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>flatten_all</name>
      <anchorfile>group__generators_ga7416f4db26c4e41360e71dd449de20a6.html</anchorfile>
      <anchor>ga7416f4db26c4e41360e71dd449de20a6</anchor>
      <arglist>(T &amp;&amp;t, Func f)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>fold_left</name>
      <anchorfile>group__reductions_ga74e253f7967cc7f188a979551cf687ef.html</anchorfile>
      <anchor>ga74e253f7967cc7f188a979551cf687ef</anchor>
      <arglist>(Function f, T &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>fold_left</name>
      <anchorfile>group__reductions_ga0f786372596b4dd7b924bf944871d7ad.html</anchorfile>
      <anchor>ga0f786372596b4dd7b924bf944871d7ad</anchor>
      <arglist>(Function f, T &amp;&amp;t, Value init)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>fold_right</name>
      <anchorfile>group__reductions_ga0f30eadf94cf474e9e54f4b6d495f4c6.html</anchorfile>
      <anchor>ga0f30eadf94cf474e9e54f4b6d495f4c6</anchor>
      <arglist>(Function f, T &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>fold_right</name>
      <anchorfile>group__reductions_ga5842a04c6880086a9fb8f3a06bc81469.html</anchorfile>
      <anchor>ga5842a04c6880086a9fb8f3a06bc81469</anchor>
      <arglist>(Function f, T &amp;&amp;t, Value init)</arglist>
    </member>
    <member kind="function">
      <type>constexpr void</type>
      <name>for_each</name>
      <anchorfile>group__transforms_gae9e3fdeaf5297101b0d0da55a883c56a.html</anchorfile>
      <anchor>gae9e3fdeaf5297101b0d0da55a883c56a</anchor>
      <arglist>(Function f, T &amp;&amp;t, Ts &amp;&amp;... ts)</arglist>
    </member>
    <member kind="function">
      <type>constexpr void</type>
      <name>for_each_field</name>
      <anchorfile>group__record__transforms_ga3ece4da34324ad360ade0bd4d174cee6.html</anchorfile>
      <anchor>ga3ece4da34324ad360ade0bd4d174cee6</anchor>
      <arglist>(Function f, R &amp;&amp;r, Rs &amp;&amp;... rs)</arglist>
    </member>
    <member kind="function">
      <type>constexpr void</type>
      <name>for_each_index</name>
      <anchorfile>group__tuple__transforms_ga3e02ab065b60cea56e0b6ac96e2ae388.html</anchorfile>
      <anchor>ga3e02ab065b60cea56e0b6ac96e2ae388</anchor>
      <arglist>(Function f, T &amp;&amp;t, Ts &amp;&amp;... ts)</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>front</name>
      <anchorfile>group__generators_ga04a99a08fa0578c39242f348dc19c8c7.html</anchorfile>
      <anchor>ga04a99a08fa0578c39242f348dc19c8c7</anchor>
      <arglist>(T &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>generate</name>
      <anchorfile>group__generators_gaf6a234ed8630b3928724cf8fefbc9c6d.html</anchorfile>
      <anchor>gaf6a234ed8630b3928724cf8fefbc9c6d</anchor>
      <arglist>(Function const &amp;f) noexcept</arglist>
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
      <type>constexpr auto</type>
      <name>inclusive_scan_left</name>
      <anchorfile>group__reductions_gab62658d582fe17a5824465ba5e669b26.html</anchorfile>
      <anchor>gab62658d582fe17a5824465ba5e669b26</anchor>
      <arglist>(Function f, T &amp;&amp;t, Value init)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>inclusive_scan_left</name>
      <anchorfile>group__reductions_ga18e1921f3f9aeb30ed0edf8ec9371577.html</anchorfile>
      <anchor>ga18e1921f3f9aeb30ed0edf8ec9371577</anchor>
      <arglist>(M &amp;&amp;m, T &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>inclusive_scan_right</name>
      <anchorfile>group__reductions_gaa626c4c72c6c4f6ac575851c0dbf06bb.html</anchorfile>
      <anchor>gaa626c4c72c6c4f6ac575851c0dbf06bb</anchor>
      <arglist>(Function f, T &amp;&amp;t, Value init)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>inclusive_scan_right</name>
      <anchorfile>group__reductions_ga12e5013494b9498224e311c8cf51a76c.html</anchorfile>
      <anchor>ga12e5013494b9498224e311c8cf51a76c</anchor>
      <arglist>(M &amp;&amp;m, T &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>consteval auto</type>
      <name>indexes</name>
      <anchorfile>group__utility_ga6882a4ada4935fa0fd4ef32ce3716ffb.html</anchorfile>
      <anchor>ga6882a4ada4935fa0fd4ef32ce3716ffb</anchor>
      <arglist>(Ts...) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>inner_product</name>
      <anchorfile>namespacekumi.html</anchorfile>
      <anchor>ab2e255186fdc3ad952d0b28418ca06a3</anchor>
      <arglist>(S1 &amp;&amp;s1, S2 &amp;&amp;s2, T init) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>inner_product</name>
      <anchorfile>group__reductions_ga152ee8c92e7bc5edc1600673dbd3d50c.html</anchorfile>
      <anchor>ga152ee8c92e7bc5edc1600673dbd3d50c</anchor>
      <arglist>(S1 &amp;&amp;s1, S2 &amp;&amp;s2, T init, Sum sum, Prod prod) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>invoke</name>
      <anchorfile>group__functional_gaf1c366392fa05d8bd5da7b91902924af.html</anchorfile>
      <anchor>gaf1c366392fa05d8bd5da7b91902924af</anchor>
      <arglist>(C &amp;&amp;c, Ts &amp;&amp;... ts) noexcept(std::is_nothrow_invocable_v&lt; C, Ts... &gt;)</arglist>
    </member>
    <member kind="function">
      <type>constexpr R</type>
      <name>invoke_r</name>
      <anchorfile>group__functional_ga2ad666793ad04ea9b66c84b83f41f375.html</anchorfile>
      <anchor>ga2ad666793ad04ea9b66c84b83f41f375</anchor>
      <arglist>(C &amp;&amp;c, Ts &amp;&amp;... ts) noexcept(std::is_nothrow_invocable_r_v&lt; R, C, Ts... &gt;)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>iota</name>
      <anchorfile>group__generators_ga19ced0b66d1e3dae7bfa60f7def6914f.html</anchorfile>
      <anchor>ga19ced0b66d1e3dae7bfa60f7def6914f</anchor>
      <arglist>(T v) noexcept</arglist>
    </member>
    <member kind="function">
      <type>consteval str</type>
      <name>label_of</name>
      <anchorfile>group__utility_gafe5ca3b16c26d385085be7a73a1fa374.html</anchorfile>
      <anchor>gafe5ca3b16c26d385085be7a73a1fa374</anchor>
      <arglist>() noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>locate</name>
      <anchorfile>group__queries_gabae586f9cb43b3fc2b2ca919518eb837.html</anchorfile>
      <anchor>gabae586f9cb43b3fc2b2ca919518eb837</anchor>
      <arglist>(T &amp;&amp;t, Pred p) noexcept</arglist>
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
      <name>map</name>
      <anchorfile>group__transforms_gaf11826c10bd2cd2c483cb09f07665dc4.html</anchorfile>
      <anchor>gaf11826c10bd2cd2c483cb09f07665dc4</anchor>
      <arglist>(Function f, T &amp;&amp;t0, Ts &amp;&amp;... others)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>map_field</name>
      <anchorfile>group__record__transforms_ga9693988b3886c889e583a99d4594e2af.html</anchorfile>
      <anchor>ga9693988b3886c889e583a99d4594e2af</anchor>
      <arglist>(Function f, T &amp;&amp;t0, Ts &amp;&amp;... others)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>map_index</name>
      <anchorfile>group__tuple__transforms_gac00fe55b0cba7a129caa2ea3d01cd1f0.html</anchorfile>
      <anchor>gac00fe55b0cba7a129caa2ea3d01cd1f0</anchor>
      <arglist>(Function f, T &amp;&amp;t0, Ts &amp;&amp;... others)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>map_reduce</name>
      <anchorfile>group__reductions_gace3f0fb4e67066f6f82052efd359b2b4.html</anchorfile>
      <anchor>gace3f0fb4e67066f6f82052efd359b2b4</anchor>
      <arglist>(Function f, M &amp;&amp;m, T &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>map_reduce</name>
      <anchorfile>group__reductions_gaa6b16ddb18150ef85f789e80593b68a2.html</anchorfile>
      <anchor>gaa6b16ddb18150ef85f789e80593b68a2</anchor>
      <arglist>(Function f, M &amp;&amp;m, T &amp;&amp;t, Value init)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>max</name>
      <anchorfile>group__reductions_ga72159dc27be6b9aed9cc1d12ca019f28.html</anchorfile>
      <anchor>ga72159dc27be6b9aed9cc1d12ca019f28</anchor>
      <arglist>(T &amp;&amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>max</name>
      <anchorfile>group__reductions_gae173eedc8b731830ea5df23aec9f14fa.html</anchorfile>
      <anchor>gae173eedc8b731830ea5df23aec9f14fa</anchor>
      <arglist>(T &amp;&amp;t, F f) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>max_flat</name>
      <anchorfile>group__reductions_gafa660a662111704882e6c9005f34f818.html</anchorfile>
      <anchor>gafa660a662111704882e6c9005f34f818</anchor>
      <arglist>(T &amp;&amp;t, F f) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>member_cast</name>
      <anchorfile>group__generators_ga79787185d26368946a74f31ce5f6597c.html</anchorfile>
      <anchor>ga79787185d26368946a74f31ce5f6597c</anchor>
      <arglist>(T &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>min</name>
      <anchorfile>group__reductions_ga2e588148a9b7eda028da7963770a5010.html</anchorfile>
      <anchor>ga2e588148a9b7eda028da7963770a5010</anchor>
      <arglist>(T &amp;&amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>min</name>
      <anchorfile>group__reductions_gab860bed731b3d7499e9d85b1a3ce57b6.html</anchorfile>
      <anchor>gab860bed731b3d7499e9d85b1a3ce57b6</anchor>
      <arglist>(T &amp;&amp;t, F f) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>min_flat</name>
      <anchorfile>group__reductions_ga931f495837b8f1c878fbb8a625ca9442.html</anchorfile>
      <anchor>ga931f495837b8f1c878fbb8a625ca9442</anchor>
      <arglist>(T &amp;&amp;t, F f) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr bool</type>
      <name>none_of</name>
      <anchorfile>group__queries_ga8094ec3fd9bb7b61c5a41319bd3f6766.html</anchorfile>
      <anchor>ga8094ec3fd9bb7b61c5a41319bd3f6766</anchor>
      <arglist>(T &amp;&amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr bool</type>
      <name>none_of</name>
      <anchorfile>group__queries_ga5450fe960cb3282fc7c2b2d072128802.html</anchorfile>
      <anchor>ga5450fe960cb3282fc7c2b2d072128802</anchor>
      <arglist>(T &amp;&amp;t, Pred p) noexcept</arglist>
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
      <name>partition</name>
      <anchorfile>group__generators_gaf7926aecf07b881c2005e39f34512851.html</anchorfile>
      <anchor>gaf7926aecf07b881c2005e39f34512851</anchor>
      <arglist>(T &amp;&amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>pop_back</name>
      <anchorfile>group__generators_gaa78a8b1a97ed4da70a1e772cafb55aef.html</anchorfile>
      <anchor>gaa78a8b1a97ed4da70a1e772cafb55aef</anchor>
      <arglist>(T &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>pop_front</name>
      <anchorfile>group__queries_ga0067bdadcb60e0eeb405bd1021dd4f08.html</anchorfile>
      <anchor>ga0067bdadcb60e0eeb405bd1021dd4f08</anchor>
      <arglist>(T &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>predicate</name>
      <anchorfile>group__utility_ga9c8c29e8a2f4f5e8a663200559fdc983.html</anchorfile>
      <anchor>ga9c8c29e8a2f4f5e8a663200559fdc983</anchor>
      <arglist>() noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>prod</name>
      <anchorfile>group__reductions_ga9c9775c7c76aebd9db20d0e44eec6034.html</anchorfile>
      <anchor>ga9c9775c7c76aebd9db20d0e44eec6034</anchor>
      <arglist>(T &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>prod</name>
      <anchorfile>group__reductions_gad87f59b6ce034ee52f7bf15e67cf7450.html</anchorfile>
      <anchor>gad87f59b6ce034ee52f7bf15e67cf7450</anchor>
      <arglist>(T &amp;&amp;t, Value init)</arglist>
    </member>
    <member kind="function">
      <type>KUMI_CUDA</type>
      <name>projection_map</name>
      <anchorfile>group__utility_ga8b7f4e6ed1e7071d7c152c9870709fcb.html</anchorfile>
      <anchor>ga8b7f4e6ed1e7071d7c152c9870709fcb</anchor>
      <arglist>(Ts...) -&gt; projection_map&lt; Ts</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>push_back</name>
      <anchorfile>group__generators_ga1caeff43037aae979c9ff1ca476091cb.html</anchorfile>
      <anchor>ga1caeff43037aae979c9ff1ca476091cb</anchor>
      <arglist>(T &amp;&amp;t, V &amp;&amp;v)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>push_front</name>
      <anchorfile>group__queries_ga45a00d0a03a72f6c0c67501e684ddbea.html</anchorfile>
      <anchor>ga45a00d0a03a72f6c0c67501e684ddbea</anchor>
      <arglist>(T &amp;&amp;t, V &amp;&amp;v)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>reduce</name>
      <anchorfile>group__reductions_ga812fe60401e985cc2ebd067bc42f0354.html</anchorfile>
      <anchor>ga812fe60401e985cc2ebd067bc42f0354</anchor>
      <arglist>(M &amp;&amp;m, T &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>reduce</name>
      <anchorfile>group__reductions_ga7d1398c56521f65375bb2f2b28e945cb.html</anchorfile>
      <anchor>ga7d1398c56521f65375bb2f2b28e945cb</anchor>
      <arglist>(M &amp;&amp;m, T &amp;&amp;t, Value init)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>reindex</name>
      <anchorfile>group__generators_ga0e43e02e9a4a7fea31b620b2dcb4b48a.html</anchorfile>
      <anchor>ga0e43e02e9a4a7fea31b620b2dcb4b48a</anchor>
      <arglist>(T &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>reorder</name>
      <anchorfile>group__generators_ga11fbe45a20286800b1d6ef15d7930d37.html</anchorfile>
      <anchor>ga11fbe45a20286800b1d6ef15d7930d37</anchor>
      <arglist>(T &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>reorder_fields</name>
      <anchorfile>group__generators_ga86a5aaefb0718b80b2103bf9dc8e3b23.html</anchorfile>
      <anchor>ga86a5aaefb0718b80b2103bf9dc8e3b23</anchor>
      <arglist>(Tuple &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>reverse</name>
      <anchorfile>group__generators_gab95d676ad41b4adc604681d14081026e.html</anchorfile>
      <anchor>gab95d676ad41b4adc604681d14081026e</anchor>
      <arglist>(T &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>rotate_left</name>
      <anchorfile>group__generators_ga969f4ebe05e88580436080ab956e7e37.html</anchorfile>
      <anchor>ga969f4ebe05e88580436080ab956e7e37</anchor>
      <arglist>(T &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>rotate_right</name>
      <anchorfile>group__generators_ga7b4c54857ff1b5253b86ae9b05098268.html</anchorfile>
      <anchor>ga7b4c54857ff1b5253b86ae9b05098268</anchor>
      <arglist>(T &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>split</name>
      <anchorfile>group__generators_ga6704d0084f5e83ac5860a75090e0e05d.html</anchorfile>
      <anchor>ga6704d0084f5e83ac5860a75090e0e05d</anchor>
      <arglist>(T &amp;&amp;t, kumi::index_t&lt; I0 &gt; i0) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>sum</name>
      <anchorfile>group__reductions_gaa96dfd76fe746fe28e1a833ad76c59fc.html</anchorfile>
      <anchor>gaa96dfd76fe746fe28e1a833ad76c59fc</anchor>
      <arglist>(T &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>sum</name>
      <anchorfile>group__reductions_ga183fa966de706e5e6c78a9cc50202fe8.html</anchorfile>
      <anchor>ga183fa966de706e5e6c78a9cc50202fe8</anchor>
      <arglist>(T &amp;&amp;t, Value init)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>tiles</name>
      <anchorfile>group__generators_ga92fa9f88804ec032d1f2bf2717205743.html</anchorfile>
      <anchor>ga92fa9f88804ec032d1f2bf2717205743</anchor>
      <arglist>(T &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>transpose</name>
      <anchorfile>group__generators_gadd1fa406983775f22d7a64bdd49e92b3.html</anchorfile>
      <anchor>gadd1fa406983775f22d7a64bdd49e92b3</anchor>
      <arglist>(T &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>unique</name>
      <anchorfile>group__generators_ga26131fc7a91a6860d0013d4be6151333.html</anchorfile>
      <anchor>ga26131fc7a91a6860d0013d4be6151333</anchor>
      <arglist>(T &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>windows</name>
      <anchorfile>group__generators_gadbca06109e5b36b0d59eab4a0fc9accf.html</anchorfile>
      <anchor>gadbca06109e5b36b0d59eab4a0fc9accf</anchor>
      <arglist>(T &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>zip</name>
      <anchorfile>group__generators_ga35d675c755f2cb5e3ad41789d5c9ca9f.html</anchorfile>
      <anchor>ga35d675c755f2cb5e3ad41789d5c9ca9f</anchor>
      <arglist>(T0 &amp;&amp;t0, Ts &amp;&amp;... ts)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>zip_max</name>
      <anchorfile>group__generators_ga778a2a1100119d65f2b64aef57bc42e7.html</anchorfile>
      <anchor>ga778a2a1100119d65f2b64aef57bc42e7</anchor>
      <arglist>(T0 &amp;&amp;t0, Ts &amp;&amp;... ts)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>zip_min</name>
      <anchorfile>group__generators_ga8b5c922e0cab8ad0a3aadd9f2af3464d.html</anchorfile>
      <anchor>ga8b5c922e0cab8ad0a3aadd9f2af3464d</anchor>
      <arglist>(T0 &amp;&amp;t0, Ts &amp;&amp;... ts)</arglist>
    </member>
    <member kind="variable">
      <type>constexpr traits_check&lt; Traits &gt;</type>
      <name>if_</name>
      <anchorfile>group__utility_gacadc026868e6654e80c57432643c804a.html</anchorfile>
      <anchor>gacadc026868e6654e80c57432643c804a</anchor>
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
      <type>constexpr kumi::label_t&lt; Label &gt;</type>
      <name>label</name>
      <anchorfile>group__utility.html</anchorfile>
      <anchor>ga1375bb29a75ab718bdb62b65ce5582b1</anchor>
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
      <type>constexpr kumi::only_t&lt; T &gt;</type>
      <name>only</name>
      <anchorfile>group__utility_ga26690952147eaa66ecf74378070ee53b.html</anchorfile>
      <anchor>ga26690952147eaa66ecf74378070ee53b</anchor>
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
    <class kind="struct">kumi::function::cartesian_product_t</class>
    <class kind="struct">kumi::function::cat_t</class>
    <class kind="struct">kumi::function::element_or</class>
    <class kind="class">kumi::function::foldable</class>
    <class kind="class">kumi::function::numeric_add</class>
    <class kind="class">kumi::function::numeric_prod</class>
    <class kind="struct">kumi::function::reduce_t</class>
    <class kind="struct">kumi::function::rotate_t</class>
    <class kind="class">kumi::function::scannable</class>
    <class kind="struct">kumi::function::select_t</class>
    <class kind="struct">kumi::function::size_or</class>
    <class kind="struct">kumi::function::split_t</class>
    <class kind="struct">kumi::function::tile_t</class>
    <class kind="struct">kumi::function::unique_t</class>
    <class kind="struct">kumi::function::zip_t</class>
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
      <anchorfile>group__functional_gaf1c366392fa05d8bd5da7b91902924af.html</anchorfile>
      <anchor>gaf1c366392fa05d8bd5da7b91902924af</anchor>
      <arglist>(C &amp;&amp;c, Ts &amp;&amp;... ts) noexcept(std::is_nothrow_invocable_v&lt; C, Ts... &gt;)</arglist>
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
      <type>constexpr kumi::function::cartesian_product_t</type>
      <name>kumi::function::cartesian_producer</name>
      <anchorfile>group__functional.html</anchorfile>
      <anchor>ga11244b3628e24a7fa165dd2962582f5f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr kumi::function::cat_t</type>
      <name>kumi::function::concatenater</name>
      <anchorfile>group__functional.html</anchorfile>
      <anchor>gabb6c41b1514ec88f14d17fb519a7508f</anchor>
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
      <type>constexpr kumi::function::reduce_t</type>
      <name>kumi::function::reducer</name>
      <anchorfile>group__functional.html</anchorfile>
      <anchor>gaec57b17c983df4b4a5f25260a4052eb3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr kumi::function::rotate_t</type>
      <name>kumi::function::rotater</name>
      <anchorfile>group__functional.html</anchorfile>
      <anchor>gab8db989a4931faeaf18cfc60eb531bc1</anchor>
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
      <type>constexpr kumi::function::split_t</type>
      <name>kumi::function::splitter</name>
      <anchorfile>group__functional.html</anchorfile>
      <anchor>gae1c486aeb2fb40acc8f8bbef10106759</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr kumi::function::tile_t</type>
      <name>kumi::function::tiler</name>
      <anchorfile>group__functional.html</anchorfile>
      <anchor>gabf1238b7b5ccb9602dd4c6f0c04afd4e</anchor>
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
      <type>constexpr kumi::function::zip_t</type>
      <name>kumi::function::zipper</name>
      <anchorfile>group__functional.html</anchorfile>
      <anchor>ga8b79749d6a360d57161f38bfdc0c4e24</anchor>
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
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::bit_and</name>
      <anchorfile>group__reductions_ga2249743d977a87399b3fd98b0cb2e55e.html</anchorfile>
      <anchor>ga2249743d977a87399b3fd98b0cb2e55e</anchor>
      <arglist>(T &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::bit_and</name>
      <anchorfile>group__reductions_ga14432e4394da47b90f34c962979da853.html</anchorfile>
      <anchor>ga14432e4394da47b90f34c962979da853</anchor>
      <arglist>(T &amp;&amp;t, Value init)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::bit_or</name>
      <anchorfile>group__reductions_gaa7d3ae229843ffb2bbcabb1427ef4979.html</anchorfile>
      <anchor>gaa7d3ae229843ffb2bbcabb1427ef4979</anchor>
      <arglist>(T &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::bit_or</name>
      <anchorfile>group__reductions_ga4b48b6259301405bba1e0944ffa6e2c7.html</anchorfile>
      <anchor>ga4b48b6259301405bba1e0944ffa6e2c7</anchor>
      <arglist>(T &amp;&amp;t, Value init)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::bit_xor</name>
      <anchorfile>group__reductions_ga19a1070aa59a1fd90bbf39b860058f9d.html</anchorfile>
      <anchor>ga19a1070aa59a1fd90bbf39b860058f9d</anchor>
      <arglist>(T &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::bit_xor</name>
      <anchorfile>group__reductions_ga521dcc4de231768115582401a1a0419b.html</anchorfile>
      <anchor>ga521dcc4de231768115582401a1a0419b</anchor>
      <arglist>(T &amp;&amp;t, Value init)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::exclusive_scan_left</name>
      <anchorfile>group__reductions_gae113f4baf3a17cc22dac25df57c06031.html</anchorfile>
      <anchor>gae113f4baf3a17cc22dac25df57c06031</anchor>
      <arglist>(Function f, T &amp;&amp;t, Value init)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::exclusive_scan_left</name>
      <anchorfile>group__reductions_ga3cba3a0d02a465184302a59f4d05bc89.html</anchorfile>
      <anchor>ga3cba3a0d02a465184302a59f4d05bc89</anchor>
      <arglist>(M &amp;&amp;m, T &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::exclusive_scan_right</name>
      <anchorfile>group__reductions_gae9b0c7f1e3d7ecc8463c7275dfad5078.html</anchorfile>
      <anchor>gae9b0c7f1e3d7ecc8463c7275dfad5078</anchor>
      <arglist>(Function f, T &amp;&amp;t, Value init)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::exclusive_scan_right</name>
      <anchorfile>group__reductions_ga33f26f28d0909a45b8e2e62b39a8bf4e.html</anchorfile>
      <anchor>ga33f26f28d0909a45b8e2e62b39a8bf4e</anchor>
      <arglist>(M &amp;&amp;m, T &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::fold_left</name>
      <anchorfile>group__reductions_ga74e253f7967cc7f188a979551cf687ef.html</anchorfile>
      <anchor>ga74e253f7967cc7f188a979551cf687ef</anchor>
      <arglist>(Function f, T &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::fold_left</name>
      <anchorfile>group__reductions_ga0f786372596b4dd7b924bf944871d7ad.html</anchorfile>
      <anchor>ga0f786372596b4dd7b924bf944871d7ad</anchor>
      <arglist>(Function f, T &amp;&amp;t, Value init)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::fold_right</name>
      <anchorfile>group__reductions_ga0f30eadf94cf474e9e54f4b6d495f4c6.html</anchorfile>
      <anchor>ga0f30eadf94cf474e9e54f4b6d495f4c6</anchor>
      <arglist>(Function f, T &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::fold_right</name>
      <anchorfile>group__reductions_ga5842a04c6880086a9fb8f3a06bc81469.html</anchorfile>
      <anchor>ga5842a04c6880086a9fb8f3a06bc81469</anchor>
      <arglist>(Function f, T &amp;&amp;t, Value init)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::inclusive_scan_left</name>
      <anchorfile>group__reductions_gab62658d582fe17a5824465ba5e669b26.html</anchorfile>
      <anchor>gab62658d582fe17a5824465ba5e669b26</anchor>
      <arglist>(Function f, T &amp;&amp;t, Value init)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::inclusive_scan_left</name>
      <anchorfile>group__reductions_ga18e1921f3f9aeb30ed0edf8ec9371577.html</anchorfile>
      <anchor>ga18e1921f3f9aeb30ed0edf8ec9371577</anchor>
      <arglist>(M &amp;&amp;m, T &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::inclusive_scan_right</name>
      <anchorfile>group__reductions_gaa626c4c72c6c4f6ac575851c0dbf06bb.html</anchorfile>
      <anchor>gaa626c4c72c6c4f6ac575851c0dbf06bb</anchor>
      <arglist>(Function f, T &amp;&amp;t, Value init)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::inclusive_scan_right</name>
      <anchorfile>group__reductions_ga12e5013494b9498224e311c8cf51a76c.html</anchorfile>
      <anchor>ga12e5013494b9498224e311c8cf51a76c</anchor>
      <arglist>(M &amp;&amp;m, T &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::inner_product</name>
      <anchorfile>group__reductions_ga152ee8c92e7bc5edc1600673dbd3d50c.html</anchorfile>
      <anchor>ga152ee8c92e7bc5edc1600673dbd3d50c</anchor>
      <arglist>(S1 &amp;&amp;s1, S2 &amp;&amp;s2, T init, Sum sum, Prod prod) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::map_reduce</name>
      <anchorfile>group__reductions_gace3f0fb4e67066f6f82052efd359b2b4.html</anchorfile>
      <anchor>gace3f0fb4e67066f6f82052efd359b2b4</anchor>
      <arglist>(Function f, M &amp;&amp;m, T &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::map_reduce</name>
      <anchorfile>group__reductions_gaa6b16ddb18150ef85f789e80593b68a2.html</anchorfile>
      <anchor>gaa6b16ddb18150ef85f789e80593b68a2</anchor>
      <arglist>(Function f, M &amp;&amp;m, T &amp;&amp;t, Value init)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::max</name>
      <anchorfile>group__reductions_ga72159dc27be6b9aed9cc1d12ca019f28.html</anchorfile>
      <anchor>ga72159dc27be6b9aed9cc1d12ca019f28</anchor>
      <arglist>(T &amp;&amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::max</name>
      <anchorfile>group__reductions_gae173eedc8b731830ea5df23aec9f14fa.html</anchorfile>
      <anchor>gae173eedc8b731830ea5df23aec9f14fa</anchor>
      <arglist>(T &amp;&amp;t, F f) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::max_flat</name>
      <anchorfile>group__reductions_gafa660a662111704882e6c9005f34f818.html</anchorfile>
      <anchor>gafa660a662111704882e6c9005f34f818</anchor>
      <arglist>(T &amp;&amp;t, F f) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::min</name>
      <anchorfile>group__reductions_ga2e588148a9b7eda028da7963770a5010.html</anchorfile>
      <anchor>ga2e588148a9b7eda028da7963770a5010</anchor>
      <arglist>(T &amp;&amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::min</name>
      <anchorfile>group__reductions_gab860bed731b3d7499e9d85b1a3ce57b6.html</anchorfile>
      <anchor>gab860bed731b3d7499e9d85b1a3ce57b6</anchor>
      <arglist>(T &amp;&amp;t, F f) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::min_flat</name>
      <anchorfile>group__reductions_ga931f495837b8f1c878fbb8a625ca9442.html</anchorfile>
      <anchor>ga931f495837b8f1c878fbb8a625ca9442</anchor>
      <arglist>(T &amp;&amp;t, F f) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::prod</name>
      <anchorfile>group__reductions_ga9c9775c7c76aebd9db20d0e44eec6034.html</anchorfile>
      <anchor>ga9c9775c7c76aebd9db20d0e44eec6034</anchor>
      <arglist>(T &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::prod</name>
      <anchorfile>group__reductions_gad87f59b6ce034ee52f7bf15e67cf7450.html</anchorfile>
      <anchor>gad87f59b6ce034ee52f7bf15e67cf7450</anchor>
      <arglist>(T &amp;&amp;t, Value init)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::reduce</name>
      <anchorfile>group__reductions_ga812fe60401e985cc2ebd067bc42f0354.html</anchorfile>
      <anchor>ga812fe60401e985cc2ebd067bc42f0354</anchor>
      <arglist>(M &amp;&amp;m, T &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::reduce</name>
      <anchorfile>group__reductions_ga7d1398c56521f65375bb2f2b28e945cb.html</anchorfile>
      <anchor>ga7d1398c56521f65375bb2f2b28e945cb</anchor>
      <arglist>(M &amp;&amp;m, T &amp;&amp;t, Value init)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::sum</name>
      <anchorfile>group__reductions_gaa96dfd76fe746fe28e1a833ad76c59fc.html</anchorfile>
      <anchor>gaa96dfd76fe746fe28e1a833ad76c59fc</anchor>
      <arglist>(T &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::sum</name>
      <anchorfile>group__reductions_ga183fa966de706e5e6c78a9cc50202fe8.html</anchorfile>
      <anchor>ga183fa966de706e5e6c78a9cc50202fe8</anchor>
      <arglist>(T &amp;&amp;t, Value init)</arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>generators</name>
    <title>Product Type Generators</title>
    <filename>group__generators.html</filename>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::all_unique</name>
      <anchorfile>group__generators_gacf670e19ac40c8981f52ad0783a3e483.html</anchorfile>
      <anchor>gacf670e19ac40c8981f52ad0783a3e483</anchor>
      <arglist>(T &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>auto</type>
      <name>kumi::as_flat_ptr</name>
      <anchorfile>group__generators_ga418f0a47f05b67dbb354d274dee63e4e.html</anchorfile>
      <anchor>ga418f0a47f05b67dbb354d274dee63e4e</anchor>
      <arglist>(T &amp;&amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>kumi::back</name>
      <anchorfile>group__generators_gacbfca9b5e95948e4180a54e920d19c6f.html</anchorfile>
      <anchor>gacbfca9b5e95948e4180a54e920d19c6f</anchor>
      <arglist>(T &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::cartesian_product</name>
      <anchorfile>group__generators_ga461b0473347a35c07e54f9b3d324ad94.html</anchorfile>
      <anchor>ga461b0473347a35c07e54f9b3d324ad94</anchor>
      <arglist>(Ts &amp;&amp;... ts)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::cat</name>
      <anchorfile>group__generators_ga54c98adccbd7a86240d50e915d789650.html</anchorfile>
      <anchor>ga54c98adccbd7a86240d50e915d789650</anchor>
      <arglist>(Ts &amp;&amp;... ts)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::chunks</name>
      <anchorfile>group__generators_ga3cb72901ec2c82a9b4d4ff5bf513237c.html</anchorfile>
      <anchor>ga3cb72901ec2c82a9b4d4ff5bf513237c</anchor>
      <arglist>(T &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::extract</name>
      <anchorfile>group__generators_ga40f37d0cfe5e51d7930c021eb67205bc.html</anchorfile>
      <anchor>ga40f37d0cfe5e51d7930c021eb67205bc</anchor>
      <arglist>(T &amp;&amp;t, kumi::index_t&lt; I0 &gt; i0, kumi::index_t&lt; I1 &gt; i1) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::fill</name>
      <anchorfile>group__generators_gac1f2b67c16429675ca7b9106793f9001.html</anchorfile>
      <anchor>gac1f2b67c16429675ca7b9106793f9001</anchor>
      <arglist>(T const &amp;v) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::filter</name>
      <anchorfile>group__generators_gaafed5030f3115f8fda5f1966a9fdfd38.html</anchorfile>
      <anchor>gaafed5030f3115f8fda5f1966a9fdfd38</anchor>
      <arglist>(T &amp;&amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::filter_not</name>
      <anchorfile>group__generators_ga4252a5ff33d90265f42d4b6c70e48bed.html</anchorfile>
      <anchor>ga4252a5ff33d90265f42d4b6c70e48bed</anchor>
      <arglist>(T &amp;&amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::flatten</name>
      <anchorfile>group__generators_ga6a021e42590689a905a2d8268c860838.html</anchorfile>
      <anchor>ga6a021e42590689a905a2d8268c860838</anchor>
      <arglist>(T &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::flatten_all</name>
      <anchorfile>group__generators_ga7416f4db26c4e41360e71dd449de20a6.html</anchorfile>
      <anchor>ga7416f4db26c4e41360e71dd449de20a6</anchor>
      <arglist>(T &amp;&amp;t, Func f)</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>kumi::front</name>
      <anchorfile>group__generators_ga04a99a08fa0578c39242f348dc19c8c7.html</anchorfile>
      <anchor>ga04a99a08fa0578c39242f348dc19c8c7</anchor>
      <arglist>(T &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::generate</name>
      <anchorfile>group__generators_gaf6a234ed8630b3928724cf8fefbc9c6d.html</anchorfile>
      <anchor>gaf6a234ed8630b3928724cf8fefbc9c6d</anchor>
      <arglist>(Function const &amp;f) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::iota</name>
      <anchorfile>group__generators_ga19ced0b66d1e3dae7bfa60f7def6914f.html</anchorfile>
      <anchor>ga19ced0b66d1e3dae7bfa60f7def6914f</anchor>
      <arglist>(T v) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::member_cast</name>
      <anchorfile>group__generators_ga79787185d26368946a74f31ce5f6597c.html</anchorfile>
      <anchor>ga79787185d26368946a74f31ce5f6597c</anchor>
      <arglist>(T &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::partition</name>
      <anchorfile>group__generators_gaf7926aecf07b881c2005e39f34512851.html</anchorfile>
      <anchor>gaf7926aecf07b881c2005e39f34512851</anchor>
      <arglist>(T &amp;&amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::pop_back</name>
      <anchorfile>group__generators_gaa78a8b1a97ed4da70a1e772cafb55aef.html</anchorfile>
      <anchor>gaa78a8b1a97ed4da70a1e772cafb55aef</anchor>
      <arglist>(T &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::push_back</name>
      <anchorfile>group__generators_ga1caeff43037aae979c9ff1ca476091cb.html</anchorfile>
      <anchor>ga1caeff43037aae979c9ff1ca476091cb</anchor>
      <arglist>(T &amp;&amp;t, V &amp;&amp;v)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::reindex</name>
      <anchorfile>group__generators_ga0e43e02e9a4a7fea31b620b2dcb4b48a.html</anchorfile>
      <anchor>ga0e43e02e9a4a7fea31b620b2dcb4b48a</anchor>
      <arglist>(T &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::reorder</name>
      <anchorfile>group__generators_ga11fbe45a20286800b1d6ef15d7930d37.html</anchorfile>
      <anchor>ga11fbe45a20286800b1d6ef15d7930d37</anchor>
      <arglist>(T &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::reorder_fields</name>
      <anchorfile>group__generators_ga86a5aaefb0718b80b2103bf9dc8e3b23.html</anchorfile>
      <anchor>ga86a5aaefb0718b80b2103bf9dc8e3b23</anchor>
      <arglist>(Tuple &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::reverse</name>
      <anchorfile>group__generators_gab95d676ad41b4adc604681d14081026e.html</anchorfile>
      <anchor>gab95d676ad41b4adc604681d14081026e</anchor>
      <arglist>(T &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::rotate_left</name>
      <anchorfile>group__generators_ga969f4ebe05e88580436080ab956e7e37.html</anchorfile>
      <anchor>ga969f4ebe05e88580436080ab956e7e37</anchor>
      <arglist>(T &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::rotate_right</name>
      <anchorfile>group__generators_ga7b4c54857ff1b5253b86ae9b05098268.html</anchorfile>
      <anchor>ga7b4c54857ff1b5253b86ae9b05098268</anchor>
      <arglist>(T &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::split</name>
      <anchorfile>group__generators_ga6704d0084f5e83ac5860a75090e0e05d.html</anchorfile>
      <anchor>ga6704d0084f5e83ac5860a75090e0e05d</anchor>
      <arglist>(T &amp;&amp;t, kumi::index_t&lt; I0 &gt; i0) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::tiles</name>
      <anchorfile>group__generators_ga92fa9f88804ec032d1f2bf2717205743.html</anchorfile>
      <anchor>ga92fa9f88804ec032d1f2bf2717205743</anchor>
      <arglist>(T &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::transpose</name>
      <anchorfile>group__generators_gadd1fa406983775f22d7a64bdd49e92b3.html</anchorfile>
      <anchor>gadd1fa406983775f22d7a64bdd49e92b3</anchor>
      <arglist>(T &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::unique</name>
      <anchorfile>group__generators_ga26131fc7a91a6860d0013d4be6151333.html</anchorfile>
      <anchor>ga26131fc7a91a6860d0013d4be6151333</anchor>
      <arglist>(T &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::windows</name>
      <anchorfile>group__generators_gadbca06109e5b36b0d59eab4a0fc9accf.html</anchorfile>
      <anchor>gadbca06109e5b36b0d59eab4a0fc9accf</anchor>
      <arglist>(T &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::zip</name>
      <anchorfile>group__generators_ga35d675c755f2cb5e3ad41789d5c9ca9f.html</anchorfile>
      <anchor>ga35d675c755f2cb5e3ad41789d5c9ca9f</anchor>
      <arglist>(T0 &amp;&amp;t0, Ts &amp;&amp;... ts)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::zip_max</name>
      <anchorfile>group__generators_ga778a2a1100119d65f2b64aef57bc42e7.html</anchorfile>
      <anchor>ga778a2a1100119d65f2b64aef57bc42e7</anchor>
      <arglist>(T0 &amp;&amp;t0, Ts &amp;&amp;... ts)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::zip_min</name>
      <anchorfile>group__generators_ga8b5c922e0cab8ad0a3aadd9f2af3464d.html</anchorfile>
      <anchor>ga8b5c922e0cab8ad0a3aadd9f2af3464d</anchor>
      <arglist>(T0 &amp;&amp;t0, Ts &amp;&amp;... ts)</arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>queries</name>
    <title>Product Type Queries</title>
    <filename>group__queries.html</filename>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::all_of</name>
      <anchorfile>group__queries_ga599b0ea5293a040316abedd19bb72f42.html</anchorfile>
      <anchor>ga599b0ea5293a040316abedd19bb72f42</anchor>
      <arglist>(T &amp;&amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::all_of</name>
      <anchorfile>group__queries_ga72fb1b09abe23dbd9c6f2783c98c0c5d.html</anchorfile>
      <anchor>ga72fb1b09abe23dbd9c6f2783c98c0c5d</anchor>
      <arglist>(T &amp;&amp;t, Pred p) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::any_of</name>
      <anchorfile>group__queries_ga372b7bd18ab6b59234a6c68d74d298cf.html</anchorfile>
      <anchor>ga372b7bd18ab6b59234a6c68d74d298cf</anchor>
      <arglist>(T &amp;&amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::any_of</name>
      <anchorfile>group__queries_ga77b8923d8b86a504f8b683d16a9f1c3b.html</anchorfile>
      <anchor>ga77b8923d8b86a504f8b683d16a9f1c3b</anchor>
      <arglist>(T &amp;&amp;t, Pred p) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::contains</name>
      <anchorfile>group__queries_ga5b1e2b6241cc570b3688866e8f729d63.html</anchorfile>
      <anchor>ga5b1e2b6241cc570b3688866e8f729d63</anchor>
      <arglist>(T &amp;&amp;t, ID const &amp;id) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::contains_any</name>
      <anchorfile>group__queries_gade57a6c7c09f285d24d85343e87247ee.html</anchorfile>
      <anchor>gade57a6c7c09f285d24d85343e87247ee</anchor>
      <arglist>(T &amp;&amp;t, Is const &amp;... ids) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::contains_none</name>
      <anchorfile>group__queries_ga1fe92be51ecab233d192ad35dd56dd3d.html</anchorfile>
      <anchor>ga1fe92be51ecab233d192ad35dd56dd3d</anchor>
      <arglist>(T &amp;&amp;t, Is const &amp;... ids) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::contains_only</name>
      <anchorfile>group__queries_gaaa6ceb114c1f1ecf07428a655923ff95.html</anchorfile>
      <anchor>gaaa6ceb114c1f1ecf07428a655923ff95</anchor>
      <arglist>(T &amp;&amp;t, Is const &amp;... ids) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr std::size_t</type>
      <name>kumi::count</name>
      <anchorfile>group__queries_ga89924270e75ae69034cab01a0136b062.html</anchorfile>
      <anchor>ga89924270e75ae69034cab01a0136b062</anchor>
      <arglist>(T &amp;&amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr std::size_t</type>
      <name>kumi::count_if</name>
      <anchorfile>group__queries_ga149410b213526c378704e3dea56559ad.html</anchorfile>
      <anchor>ga149410b213526c378704e3dea56559ad</anchor>
      <arglist>(T &amp;&amp;t, Pred p) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::locate</name>
      <anchorfile>group__queries_gabae586f9cb43b3fc2b2ca919518eb837.html</anchorfile>
      <anchor>gabae586f9cb43b3fc2b2ca919518eb837</anchor>
      <arglist>(T &amp;&amp;t, Pred p) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr bool</type>
      <name>kumi::none_of</name>
      <anchorfile>group__queries_ga8094ec3fd9bb7b61c5a41319bd3f6766.html</anchorfile>
      <anchor>ga8094ec3fd9bb7b61c5a41319bd3f6766</anchor>
      <arglist>(T &amp;&amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr bool</type>
      <name>kumi::none_of</name>
      <anchorfile>group__queries_ga5450fe960cb3282fc7c2b2d072128802.html</anchorfile>
      <anchor>ga5450fe960cb3282fc7c2b2d072128802</anchor>
      <arglist>(T &amp;&amp;t, Pred p) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::pop_front</name>
      <anchorfile>group__queries_ga0067bdadcb60e0eeb405bd1021dd4f08.html</anchorfile>
      <anchor>ga0067bdadcb60e0eeb405bd1021dd4f08</anchor>
      <arglist>(T &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::push_front</name>
      <anchorfile>group__queries_ga45a00d0a03a72f6c0c67501e684ddbea.html</anchorfile>
      <anchor>ga45a00d0a03a72f6c0c67501e684ddbea</anchor>
      <arglist>(T &amp;&amp;t, V &amp;&amp;v)</arglist>
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
    <concept>kumi::concepts::queryable_by_type</concept>
    <concept>kumi::concepts::record_type</concept>
    <concept>kumi::concepts::sized_product_type</concept>
    <concept>kumi::concepts::sized_product_type_or_more</concept>
    <concept>kumi::concepts::static_container</concept>
    <concept>kumi::concepts::uniquely_labeled</concept>
    <concept>kumi::concepts::uniquely_named</concept>
    <concept>kumi::concepts::uniquely_typed</concept>
    <concept>kumi::concepts::unit_type</concept>
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
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>kumi::apply</name>
      <anchorfile>group__transforms_ga9982fadb19cb52094d6165bca7f57f25.html</anchorfile>
      <anchor>ga9982fadb19cb52094d6165bca7f57f25</anchor>
      <arglist>(Function &amp;&amp;f, T &amp;&amp;t) noexcept(kumi_implementation_defined)</arglist>
    </member>
    <member kind="function">
      <type>constexpr void</type>
      <name>kumi::for_each</name>
      <anchorfile>group__transforms_gae9e3fdeaf5297101b0d0da55a883c56a.html</anchorfile>
      <anchor>gae9e3fdeaf5297101b0d0da55a883c56a</anchor>
      <arglist>(Function f, T &amp;&amp;t, Ts &amp;&amp;... ts)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::map</name>
      <anchorfile>group__transforms_gaf11826c10bd2cd2c483cb09f07665dc4.html</anchorfile>
      <anchor>gaf11826c10bd2cd2c483cb09f07665dc4</anchor>
      <arglist>(Function f, T &amp;&amp;t0, Ts &amp;&amp;... others)</arglist>
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
    <member kind="function">
      <type>constexpr void</type>
      <name>kumi::for_each_field</name>
      <anchorfile>group__record__transforms_ga3ece4da34324ad360ade0bd4d174cee6.html</anchorfile>
      <anchor>ga3ece4da34324ad360ade0bd4d174cee6</anchor>
      <arglist>(Function f, R &amp;&amp;r, Rs &amp;&amp;... rs)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::map_field</name>
      <anchorfile>group__record__transforms_ga9693988b3886c889e583a99d4594e2af.html</anchorfile>
      <anchor>ga9693988b3886c889e583a99d4594e2af</anchor>
      <arglist>(Function f, T &amp;&amp;t0, Ts &amp;&amp;... others)</arglist>
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
    <member kind="function">
      <type>constexpr void</type>
      <name>kumi::for_each_index</name>
      <anchorfile>group__tuple__transforms_ga3e02ab065b60cea56e0b6ac96e2ae388.html</anchorfile>
      <anchor>ga3e02ab065b60cea56e0b6ac96e2ae388</anchor>
      <arglist>(Function f, T &amp;&amp;t, Ts &amp;&amp;... ts)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::map_index</name>
      <anchorfile>group__tuple__transforms_gac00fe55b0cba7a129caa2ea3d01cd1f0.html</anchorfile>
      <anchor>gac00fe55b0cba7a129caa2ea3d01cd1f0</anchor>
      <arglist>(Function f, T &amp;&amp;t0, Ts &amp;&amp;... others)</arglist>
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
