<?xml version='1.0' encoding='UTF-8' standalone='yes' ?>
<tagfile doxygen_version="1.16.1" doxygen_gitid="669aeeefca743c148e2d935b3d3c69535c7491e6">
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
    <name>kumi::boolean_and</name>
    <filename>structkumi_1_1boolean__and.html</filename>
    <member kind="variable" static="yes">
      <type>static constexpr bool</type>
      <name>identity</name>
      <anchorfile>structkumi_1_1boolean__and.html</anchorfile>
      <anchor>a6c913bae350931cb94b298fa084dc4dc</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>kumi::boolean_or</name>
    <filename>structkumi_1_1boolean__or.html</filename>
    <member kind="variable" static="yes">
      <type>static constexpr bool</type>
      <name>identity</name>
      <anchorfile>structkumi_1_1boolean__or.html</anchorfile>
      <anchor>a911bc467c38ab50adb4045058e5340be</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>kumi::boolean_xor</name>
    <filename>structkumi_1_1boolean__xor.html</filename>
    <member kind="variable" static="yes">
      <type>static constexpr bool</type>
      <name>identity</name>
      <anchorfile>structkumi_1_1boolean__xor.html</anchorfile>
      <anchor>a4278a7a826eea1d0843968167b7a458f</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>kumi::builder</name>
    <filename>structkumi_1_1builder.html</filename>
    <templarg>typename T</templarg>
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
  <compound kind="class">
    <name>kumi::field</name>
    <filename>structkumi_1_1field.html</filename>
    <templarg>typename Id</templarg>
    <templarg>typename T</templarg>
    <member kind="function" static="yes">
      <type>static constexpr auto</type>
      <name>name</name>
      <anchorfile>structkumi_1_1field.html</anchorfile>
      <anchor>af1f56e6cdc96a662408a06cd6e2b315d</anchor>
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
      <name>name</name>
      <anchorfile>structkumi_1_1field_3_01Id_00_01T_01_4.html</anchorfile>
      <anchor>af1f56e6cdc96a662408a06cd6e2b315d</anchor>
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
      <name>tag_type</name>
      <anchorfile>structkumi_1_1identifier.html</anchorfile>
      <anchor>ac47d69746c95cdade5ce1b4ed27f420d</anchor>
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
      <anchorfile>structkumi_1_1identifier_a798bf4a4c25e990142d2fdc70eba1a03.html</anchorfile>
      <anchor>a798bf4a4c25e990142d2fdc70eba1a03</anchor>
      <arglist>(T &amp;&amp;v) const noexcept -&gt; field&lt; tag_type, std::unwrap_ref_decay_t&lt; T &gt; &gt;</arglist>
    </member>
    <member kind="friend">
      <type>friend constexpr str</type>
      <name>to_str</name>
      <anchorfile>structkumi_1_1identifier.html</anchorfile>
      <anchor>af930e789056d8e6242d7f6260e83e8a1</anchor>
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
    <name>kumi::is_record_type</name>
    <filename>structkumi_1_1is__record__type.html</filename>
    <templarg>typename T</templarg>
    <templarg>typename Enable</templarg>
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
    <templarg>str ID</templarg>
    <member kind="typedef">
      <type>name&lt; ID &gt;</type>
      <name>tag_type</name>
      <anchorfile>structkumi_1_1name.html</anchorfile>
      <anchor>a62214f6cc70adbcac24737f26cd0608c</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>operator=</name>
      <anchorfile>structkumi_1_1name_a511c2175f20315a1ba432266932e36b4.html</anchorfile>
      <anchor>a511c2175f20315a1ba432266932e36b4</anchor>
      <arglist>(T &amp;&amp;v) const noexcept -&gt; field&lt; tag_type, std::unwrap_ref_decay_t&lt; T &gt; &gt;</arglist>
    </member>
    <member kind="friend">
      <type>friend constexpr str</type>
      <name>to_str</name>
      <anchorfile>structkumi_1_1name.html</anchorfile>
      <anchor>ae2ac3288ad708776a4933515f3e41b4f</anchor>
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
    <name>kumi::numeric_add</name>
    <filename>structkumi_1_1numeric__add.html</filename>
    <member kind="variable" static="yes">
      <type>static constexpr auto</type>
      <name>identity</name>
      <anchorfile>structkumi_1_1numeric__add.html</anchorfile>
      <anchor>ab861a751b5a97864feb3e5241411158e</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>kumi::numeric_prod</name>
    <filename>structkumi_1_1numeric__prod.html</filename>
    <member kind="variable" static="yes">
      <type>static constexpr auto</type>
      <name>identity</name>
      <anchorfile>structkumi_1_1numeric__prod.html</anchorfile>
      <anchor>a88d04ea20fb36bc95950974133d88454</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>kumi::projection_map</name>
    <filename>structkumi_1_1projection__map.html</filename>
    <templarg>typename... V</templarg>
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
    <name>kumi::raw_element</name>
    <filename>structkumi_1_1raw__element.html</filename>
    <templarg>std::size_t I</templarg>
    <templarg>typename T</templarg>
  </compound>
  <compound kind="struct">
    <name>kumi::raw_member</name>
    <filename>structkumi_1_1raw__member.html</filename>
    <templarg>std::size_t I</templarg>
    <templarg>typename T</templarg>
  </compound>
  <compound kind="class">
    <name>kumi::record</name>
    <filename>structkumi_1_1record.html</filename>
    <templarg>typename... Ts</templarg>
    <member kind="function">
      <type>constexpr record &amp;</type>
      <name>operator=</name>
      <anchorfile>structkumi_1_1record.html</anchorfile>
      <anchor>aa9c57533762ddcc6513cb88e6ed0911f</anchor>
      <arglist>(record&lt; Us... &gt; &amp;&amp;other)</arglist>
    </member>
    <member kind="function">
      <type>constexpr record &amp;</type>
      <name>operator=</name>
      <anchorfile>structkumi_1_1record_a257458f70bc3f0d40e580fe65b306c01.html</anchorfile>
      <anchor>a257458f70bc3f0d40e580fe65b306c01</anchor>
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
      <anchorfile>structkumi_1_1record_a5a012714bc455693e01bc348ce2b057b.html</anchorfile>
      <anchor>a5a012714bc455693e01bc348ce2b057b</anchor>
      <arglist>(index_t&lt; I &gt;) &amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1record.html</anchorfile>
      <anchor>a7e8e6db6a6efaefe471c4ed54c168ee4</anchor>
      <arglist>(index_t&lt; I &gt;) &amp;&amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1record.html</anchorfile>
      <anchor>a0cb214a3936467b51a1ad6d97b878db8</anchor>
      <arglist>(index_t&lt; I &gt;) const &amp;&amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1record.html</anchorfile>
      <anchor>a11c78900872267b0016d387a41f7dc55</anchor>
      <arglist>(index_t&lt; I &gt;) const &amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1record_a361e3ac124ed31f363463832aa32522c.html</anchorfile>
      <anchor>a361e3ac124ed31f363463832aa32522c</anchor>
      <arglist>(as&lt; T &gt;) &amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1record.html</anchorfile>
      <anchor>ab9266bec6188660d7f70ed943c6cab16</anchor>
      <arglist>(as&lt; T &gt;) &amp;&amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1record.html</anchorfile>
      <anchor>a5f7674d288caad840a0869282f2185d7</anchor>
      <arglist>(as&lt; T &gt;) const &amp;&amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1record.html</anchorfile>
      <anchor>a686208ca215e84263e812680c9f546cf</anchor>
      <arglist>(as&lt; T &gt;) const &amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1record_a25f8fd7cb11f94e3815c0045ae39c338.html</anchorfile>
      <anchor>a25f8fd7cb11f94e3815c0045ae39c338</anchor>
      <arglist>(Name const &amp;) &amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1record.html</anchorfile>
      <anchor>ae1243103f72d4a853360bba2a3547d6a</anchor>
      <arglist>(Name const &amp;) &amp;&amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1record.html</anchorfile>
      <anchor>a3ad671ad04ef78be5cbdfa0583011fef</anchor>
      <arglist>(Name const &amp;) const &amp;&amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1record.html</anchorfile>
      <anchor>a75cf6645da0961365030b311f167b602</anchor>
      <arglist>(Name const &amp;) const &amp;noexcept</arglist>
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
      <name>names</name>
      <anchorfile>structkumi_1_1record.html</anchorfile>
      <anchor>a9270cbaf244c6b4ee80cc66a175c95c7</anchor>
      <arglist>() noexcept</arglist>
    </member>
    <member kind="friend">
      <type>friend constexpr auto</type>
      <name>operator==</name>
      <anchorfile>structkumi_1_1record.html</anchorfile>
      <anchor>a451ebda777651647641516bddd22e1b1</anchor>
      <arglist>(record const &amp;self, record&lt; Us... &gt; const &amp;other) noexcept</arglist>
    </member>
    <member kind="friend">
      <type>friend constexpr auto</type>
      <name>operator!=</name>
      <anchorfile>structkumi_1_1record.html</anchorfile>
      <anchor>ac16fc65057dc76548f4a7b6b766d70e3</anchor>
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
    <name>kumi::size</name>
    <filename>structkumi_1_1size.html</filename>
    <templarg>typename T</templarg>
  </compound>
  <compound kind="class">
    <name>kumi::str</name>
    <filename>structkumi_1_1str.html</filename>
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
      <anchorfile>structkumi_1_1tuple_a0c4404dcef281e2861393df6bb517e39.html</anchorfile>
      <anchor>a0c4404dcef281e2861393df6bb517e39</anchor>
      <arglist>(index_t&lt; I &gt; i) &amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>a5960e5d8bfaaaada3245a3f153c134bd</anchor>
      <arglist>(index_t&lt; I &gt;) &amp;&amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>a8dee9f776d5da360bbcfe58d03f28e3f</anchor>
      <arglist>(index_t&lt; I &gt;) const &amp;&amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>ad9d54c3d6e6d1e22cf1972e2a1088a1a</anchor>
      <arglist>(index_t&lt; I &gt;) const &amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1tuple_af6bbf8ab193e8a4d8de340aa150e30dc.html</anchorfile>
      <anchor>af6bbf8ab193e8a4d8de340aa150e30dc</anchor>
      <arglist>(as&lt; T &gt;) &amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>a0f88183ec73ad29ba6edb4a2049b3734</anchor>
      <arglist>(as&lt; T &gt;) &amp;&amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>a1729c193b404ac36671f4feb4938aeeb</anchor>
      <arglist>(as&lt; T &gt;) const &amp;&amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>ab9e82044727515d986bda7cdc56d81ad</anchor>
      <arglist>(as&lt; T &gt;) const &amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1tuple_ac84a73920267368533a3c8c9f5b760d8.html</anchorfile>
      <anchor>ac84a73920267368533a3c8c9f5b760d8</anchor>
      <arglist>(Name const &amp;) &amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>a4e06223f547d9e3425c71ce7fd7562a6</anchor>
      <arglist>(Name const &amp;) &amp;&amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>ae2c97f7ff55e6be596702a09d20d04f6</anchor>
      <arglist>(Name const &amp;) const &amp;&amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>a664320001d03a9ca98da755c47cf009d</anchor>
      <arglist>(Name const &amp;) const &amp;noexcept</arglist>
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
      <name>names</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>afcd61db36e2c7c37134ef2bea60546eb</anchor>
      <arglist>() noexcept</arglist>
    </member>
    <member kind="friend">
      <type>friend constexpr auto</type>
      <name>operator==</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>acebb3ddeaa684e400b25f48849147641</anchor>
      <arglist>(tuple const &amp;self, tuple&lt; Us... &gt; const &amp;other) noexcept</arglist>
    </member>
    <member kind="friend">
      <type>friend constexpr auto</type>
      <name>operator!=</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>af856ef0275e81074321d1df95774850e</anchor>
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
  <compound kind="class">
    <name>kumi::unit</name>
    <filename>structkumi_1_1unit.html</filename>
  </compound>
  <compound kind="class">
    <name>kumi::unknown</name>
    <filename>structkumi_1_1unknown.html</filename>
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
    <name>kumi::concepts::contains_field</name>
    <filename>conceptkumi_1_1concepts_1_1contains__field.html</filename>
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
    <name>kumi::concepts::entirely_uniquely_named</name>
    <filename>conceptkumi_1_1concepts_1_1entirely__uniquely__named.html</filename>
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
    <name>kumi::concepts::is_fully_named</name>
    <filename>conceptkumi_1_1concepts_1_1is__fully__named.html</filename>
  </compound>
  <compound kind="concept">
    <name>kumi::concepts::monoid</name>
    <filename>conceptkumi_1_1concepts_1_1monoid.html</filename>
  </compound>
  <compound kind="concept">
    <name>kumi::concepts::named_equality_comparable</name>
    <filename>conceptkumi_1_1concepts_1_1named__equality__comparable.html</filename>
  </compound>
  <compound kind="concept">
    <name>kumi::concepts::named_get_compliant</name>
    <filename>conceptkumi_1_1concepts_1_1named__get__compliant.html</filename>
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
    <name>kumi::concepts::typed_get_compliant</name>
    <filename>conceptkumi_1_1concepts_1_1typed__get__compliant.html</filename>
  </compound>
  <compound kind="concept">
    <name>kumi::concepts::unique_label</name>
    <filename>conceptkumi_1_1concepts_1_1unique__label.html</filename>
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
    <class kind="class">kumi::as</class>
    <class kind="struct">kumi::as_tuple</class>
    <class kind="class">kumi::boolean_and</class>
    <class kind="class">kumi::boolean_or</class>
    <class kind="class">kumi::boolean_xor</class>
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
    <class kind="struct">kumi::is_homogeneous</class>
    <class kind="struct">kumi::is_product_type</class>
    <class kind="struct">kumi::is_record_type</class>
    <class kind="struct">kumi::member</class>
    <class kind="class">kumi::name</class>
    <class kind="class">kumi::numeric_add</class>
    <class kind="class">kumi::numeric_prod</class>
    <class kind="class">kumi::projection_map</class>
    <class kind="struct">kumi::raw_element</class>
    <class kind="struct">kumi::raw_member</class>
    <class kind="class">kumi::record</class>
    <class kind="struct">kumi::size</class>
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
      <anchorfile>group__generators_ga0cf18e9f5c176d132be6afbfcb6652ae.html</anchorfile>
      <anchor>ga0cf18e9f5c176d132be6afbfcb6652ae</anchor>
      <arglist>(Ts &amp;&amp;... ts)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>cat</name>
      <anchorfile>group__generators_ga3786266bedb7981ba0df79cc5b49b261.html</anchorfile>
      <anchor>ga3786266bedb7981ba0df79cc5b49b261</anchor>
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
      <type>constexpr bool</type>
      <name>contains</name>
      <anchorfile>group__queries_gad40223aadd1f05d53a30e36f679d4d4a.html</anchorfile>
      <anchor>gad40223aadd1f05d53a30e36f679d4d4a</anchor>
      <arglist>(T &amp;&amp;t, ID const &amp;id) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr bool</type>
      <name>contains_any</name>
      <anchorfile>group__queries_ga99602610074451fe87591793d992ba01.html</anchorfile>
      <anchor>ga99602610074451fe87591793d992ba01</anchor>
      <arglist>(T &amp;&amp;t, Is const &amp;... ids) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr bool</type>
      <name>contains_none</name>
      <anchorfile>group__queries_gaaa03ad56a0a8a76d8a6e88557cab92a1.html</anchorfile>
      <anchor>gaaa03ad56a0a8a76d8a6e88557cab92a1</anchor>
      <arglist>(T &amp;&amp;t, Is const &amp;... ids) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr bool</type>
      <name>contains_only</name>
      <anchorfile>group__queries_ga0c0a9c717f4825fcb0a75add9bf2a838.html</anchorfile>
      <anchor>ga0c0a9c717f4825fcb0a75add9bf2a838</anchor>
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
      <anchor>ad83dda57042b4ce386753e09745671e2</anchor>
      <arglist>(T &amp;&amp;t, index_t&lt; I0 &gt; i0) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>extract</name>
      <anchorfile>group__generators_ga2238e054e2c2a2160bec88e3c47e7691.html</anchorfile>
      <anchor>ga2238e054e2c2a2160bec88e3c47e7691</anchor>
      <arglist>(T &amp;&amp;t, index_t&lt; I0 &gt; i0, index_t&lt; I1 &gt; i1) noexcept</arglist>
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
      <anchorfile>group__transforms_ga743a481a92dcc85b86159a44a562dd77.html</anchorfile>
      <anchor>ga743a481a92dcc85b86159a44a562dd77</anchor>
      <arglist>(Function f, T &amp;&amp;t, Ts &amp;&amp;... ts)</arglist>
    </member>
    <member kind="function">
      <type>constexpr void</type>
      <name>for_each_field</name>
      <anchorfile>group__record__transforms_ga15399097726371208bf338ce69088447.html</anchorfile>
      <anchor>ga15399097726371208bf338ce69088447</anchor>
      <arglist>(Function f, R &amp;&amp;r, Rs &amp;&amp;... rs)</arglist>
    </member>
    <member kind="function">
      <type>constexpr void</type>
      <name>for_each_index</name>
      <anchorfile>group__tuple__transforms_ga68e0e98957242f48da8dfeeaa29fec7d.html</anchorfile>
      <anchor>ga68e0e98957242f48da8dfeeaa29fec7d</anchor>
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
      <anchorfile>group__utility_ga7684fa136df06ed30bdce81ccb4475c1.html</anchorfile>
      <anchor>ga7684fa136df06ed30bdce81ccb4475c1</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>consteval auto</type>
      <name>get_index_of_type</name>
      <anchorfile>group__utility_ga0b0bdfb8f39bc89d0f6cfbe1a01d341a.html</anchorfile>
      <anchor>ga0b0bdfb8f39bc89d0f6cfbe1a01d341a</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>consteval auto</type>
      <name>identifiers</name>
      <anchorfile>group__utility_ga39745d8d55ea398d3e77d719b5bf14f9.html</anchorfile>
      <anchor>ga39745d8d55ea398d3e77d719b5bf14f9</anchor>
      <arglist>(Ts... ts) noexcept</arglist>
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
      <anchorfile>group__utility_gad9d978893c5e64520e0b0d83d133c26c.html</anchorfile>
      <anchor>gad9d978893c5e64520e0b0d83d133c26c</anchor>
      <arglist>(Ts... ts) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>inner_product</name>
      <anchorfile>namespacekumi.html</anchorfile>
      <anchor>aecc2a0ba7a4f6dce228e0c5181889668</anchor>
      <arglist>(S1 &amp;&amp;s1, S2 &amp;&amp;s2, T init) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>inner_product</name>
      <anchorfile>group__reductions_gae9e0f77ffe8399c701ba32532db19d11.html</anchorfile>
      <anchor>gae9e0f77ffe8399c701ba32532db19d11</anchor>
      <arglist>(S1 &amp;&amp;s1, S2 &amp;&amp;s2, T init, Sum sum, Prod prod) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>invoke</name>
      <anchorfile>group__utility_gab575cbbe8a1b85d03353f65128d351ac.html</anchorfile>
      <anchor>gab575cbbe8a1b85d03353f65128d351ac</anchor>
      <arglist>(C &amp;&amp;c, Ts &amp;&amp;... ts) noexcept(std::is_nothrow_invocable&lt; C, Ts... &gt;::value)</arglist>
    </member>
    <member kind="function">
      <type>constexpr R</type>
      <name>invoke_r</name>
      <anchorfile>group__utility_ga81fb4720ada9b1bff437c3340fcc98b0.html</anchorfile>
      <anchor>ga81fb4720ada9b1bff437c3340fcc98b0</anchor>
      <arglist>(C &amp;&amp;c, Ts &amp;&amp;... ts) noexcept(std::is_nothrow_invocable_r&lt; R, C, Ts... &gt;::value)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>iota</name>
      <anchorfile>group__generators_ga19ced0b66d1e3dae7bfa60f7def6914f.html</anchorfile>
      <anchor>ga19ced0b66d1e3dae7bfa60f7def6914f</anchor>
      <arglist>(T v) noexcept</arglist>
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
      <anchorfile>group__transforms_ga446a1438a421885ef0a52c3933d0be5a.html</anchorfile>
      <anchor>ga446a1438a421885ef0a52c3933d0be5a</anchor>
      <arglist>(Function f, T &amp;&amp;t0, Ts &amp;&amp;... others)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>map_field</name>
      <anchorfile>group__record__transforms_ga325ce53da1e1706c3bba9c40e8477f20.html</anchorfile>
      <anchor>ga325ce53da1e1706c3bba9c40e8477f20</anchor>
      <arglist>(Function f, T &amp;&amp;t0, Ts &amp;&amp;... others)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>map_index</name>
      <anchorfile>group__tuple__transforms_ga23eac0bc61cc84e8feabf8f67f438124.html</anchorfile>
      <anchor>ga23eac0bc61cc84e8feabf8f67f438124</anchor>
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
      <name>members_of</name>
      <anchorfile>group__utility_gaba7cff8d6c8c8b6d03ca78df63c9eba0.html</anchorfile>
      <anchor>gaba7cff8d6c8c8b6d03ca78df63c9eba0</anchor>
      <arglist>(as&lt; T &gt;) noexcept</arglist>
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
      <type>consteval auto</type>
      <name>name_of</name>
      <anchorfile>group__utility_ga3413ef51638ae8c63325bedd76a75b0a.html</anchorfile>
      <anchor>ga3413ef51638ae8c63325bedd76a75b0a</anchor>
      <arglist>() noexcept</arglist>
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
      <anchorfile>group__utility_ga3ba127205027539b3090467e2a504a24.html</anchorfile>
      <anchor>ga3ba127205027539b3090467e2a504a24</anchor>
      <arglist>(Ts...) -&gt; projection_map&lt; Ts... &gt;</arglist>
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
      <anchorfile>group__generators_ga9a705331b78493a8882f9db889b57bc9.html</anchorfile>
      <anchor>ga9a705331b78493a8882f9db889b57bc9</anchor>
      <arglist>(T &amp;&amp;t, index_t&lt; I0 &gt; i0) noexcept</arglist>
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
      <name>values_of</name>
      <anchorfile>group__utility_ga62d44b638af9c683a8040a476518990e.html</anchorfile>
      <anchor>ga62d44b638af9c683a8040a476518990e</anchor>
      <arglist>(T &amp;&amp;t) noexcept</arglist>
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
      <anchorfile>group__generators_ga6fcdd03f2a3360cbb976cf05e0b0468c.html</anchorfile>
      <anchor>ga6fcdd03f2a3360cbb976cf05e0b0468c</anchor>
      <arglist>(T0 &amp;&amp;t0, Ts &amp;&amp;... ts)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>zip_max</name>
      <anchorfile>group__generators_gad2b81bc979a4089affddfdbef866e80b.html</anchorfile>
      <anchor>gad2b81bc979a4089affddfdbef866e80b</anchor>
      <arglist>(T0 &amp;&amp;t0, Ts &amp;&amp;... ts)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>zip_min</name>
      <anchorfile>group__generators_ga90d498013e5f387b2c906a4184644979.html</anchorfile>
      <anchor>ga90d498013e5f387b2c906a4184644979</anchor>
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
      <type>constexpr index_t&lt; N &gt; const</type>
      <name>index</name>
      <anchorfile>group__utility.html</anchorfile>
      <anchor>ga32a67892e5dbfb93a2292959a5a029d0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>is_projection_map_v</name>
      <anchorfile>group__traits_ga3a312d9c4dd445cbd5d152c6a02ca015.html</anchorfile>
      <anchor>ga3a312d9c4dd445cbd5d152c6a02ca015</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr unit</type>
      <name>none</name>
      <anchorfile>group__utility.html</anchorfile>
      <anchor>gabe662caa7eff683f6b085c7abb76391b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr only_t&lt; T &gt;</type>
      <name>only</name>
      <anchorfile>group__utility_ga6a8e75139bc622fbedae986420916d98.html</anchorfile>
      <anchor>ga6a8e75139bc622fbedae986420916d98</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>from_tuple</name>
      <anchorfile>group__tuple__related_gaf717514dbb49e0bf526bf5c9e2c693c5.html</anchorfile>
      <anchor>gaf717514dbb49e0bf526bf5c9e2c693c5</anchor>
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
      <anchor>a74db3542e4e4c5fab79b01cda617d964</anchor>
      <arglist>(S &amp;&amp;s)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>tie</name>
      <anchorfile>group__record__related_ga3908d4824c3feaf359d906b670ad8439.html</anchorfile>
      <anchor>ga3908d4824c3feaf359d906b670ad8439</anchor>
      <arglist>(Ts &amp;... ts) -&gt; record&lt; field&lt; decltype(Fields), Ts &amp; &gt;... &gt; requires(sizeof...(Fields)==sizeof...(Ts))</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>forward_as_record</name>
      <anchorfile>group__record__related_ga8f10ae45fab799e4d4c03d9aca17f68c.html</anchorfile>
      <anchor>ga8f10ae45fab799e4d4c03d9aca17f68c</anchor>
      <arglist>(Ts &amp;&amp;... ts) -&gt; record&lt; field&lt; decltype(Fields), Ts &amp;&amp; &gt;... &gt; requires(sizeof...(Fields)==sizeof...(Ts))</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>make_record</name>
      <anchorfile>group__record__related_ga76eb17a90f4e3752c96633b20a62969f.html</anchorfile>
      <anchor>ga76eb17a90f4e3752c96633b20a62969f</anchor>
      <arglist>(Ts &amp;&amp;... ts) -&gt; record&lt; std::unwrap_ref_decay_t&lt; Ts &gt;... &gt; requires(concepts::entirely_uniquely_named&lt; Ts... &gt;)</arglist>
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
      <anchorfile>group__record__related_ga7c267951118dab695ae5bd0f4d64895e.html</anchorfile>
      <anchor>ga7c267951118dab695ae5bd0f4d64895e</anchor>
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
      <anchorfile>group__tuple__related_ga1a3be7d170cb81c6f87c93a0a04eabc8.html</anchorfile>
      <anchor>ga1a3be7d170cb81c6f87c93a0a04eabc8</anchor>
      <arglist>(Ts &amp;... ts) -&gt; tuple&lt; Ts &amp;... &gt;</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>forward_as_tuple</name>
      <anchorfile>group__tuple__related_ga5288a0680596f3c52e7313b964a60746.html</anchorfile>
      <anchor>ga5288a0680596f3c52e7313b964a60746</anchor>
      <arglist>(Ts &amp;&amp;... ts) -&gt; tuple&lt; Ts &amp;&amp;... &gt;</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>make_tuple</name>
      <anchorfile>group__tuple__related_ga98e6c367de0e0f526565280a0856b007.html</anchorfile>
      <anchor>ga98e6c367de0e0f526565280a0856b007</anchor>
      <arglist>(Ts &amp;&amp;... ts) -&gt; tuple&lt; std::unwrap_ref_decay_t&lt; Ts &gt;... &gt;</arglist>
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
    <class kind="class">kumi::boolean_and</class>
    <class kind="class">kumi::boolean_or</class>
    <class kind="class">kumi::boolean_xor</class>
    <class kind="class">kumi::builder</class>
    <class kind="class">kumi::numeric_add</class>
    <class kind="class">kumi::numeric_prod</class>
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
      <anchorfile>group__utility_ga7684fa136df06ed30bdce81ccb4475c1.html</anchorfile>
      <anchor>ga7684fa136df06ed30bdce81ccb4475c1</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>consteval auto</type>
      <name>kumi::get_index_of_type</name>
      <anchorfile>group__utility_ga0b0bdfb8f39bc89d0f6cfbe1a01d341a.html</anchorfile>
      <anchor>ga0b0bdfb8f39bc89d0f6cfbe1a01d341a</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>consteval auto</type>
      <name>kumi::identifiers</name>
      <anchorfile>group__utility_ga39745d8d55ea398d3e77d719b5bf14f9.html</anchorfile>
      <anchor>ga39745d8d55ea398d3e77d719b5bf14f9</anchor>
      <arglist>(Ts... ts) noexcept</arglist>
    </member>
    <member kind="function">
      <type>consteval auto</type>
      <name>kumi::indexes</name>
      <anchorfile>group__utility_gad9d978893c5e64520e0b0d83d133c26c.html</anchorfile>
      <anchor>gad9d978893c5e64520e0b0d83d133c26c</anchor>
      <arglist>(Ts... ts) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>kumi::invoke</name>
      <anchorfile>group__utility_gab575cbbe8a1b85d03353f65128d351ac.html</anchorfile>
      <anchor>gab575cbbe8a1b85d03353f65128d351ac</anchor>
      <arglist>(C &amp;&amp;c, Ts &amp;&amp;... ts) noexcept(std::is_nothrow_invocable&lt; C, Ts... &gt;::value)</arglist>
    </member>
    <member kind="function">
      <type>constexpr R</type>
      <name>kumi::invoke_r</name>
      <anchorfile>group__utility_ga81fb4720ada9b1bff437c3340fcc98b0.html</anchorfile>
      <anchor>ga81fb4720ada9b1bff437c3340fcc98b0</anchor>
      <arglist>(C &amp;&amp;c, Ts &amp;&amp;... ts) noexcept(std::is_nothrow_invocable_r&lt; R, C, Ts... &gt;::value)</arglist>
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
      <name>kumi::members_of</name>
      <anchorfile>group__utility_gaba7cff8d6c8c8b6d03ca78df63c9eba0.html</anchorfile>
      <anchor>gaba7cff8d6c8c8b6d03ca78df63c9eba0</anchor>
      <arglist>(as&lt; T &gt;) noexcept</arglist>
    </member>
    <member kind="function">
      <type>consteval auto</type>
      <name>kumi::name_of</name>
      <anchorfile>group__utility_ga3413ef51638ae8c63325bedd76a75b0a.html</anchorfile>
      <anchor>ga3413ef51638ae8c63325bedd76a75b0a</anchor>
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
      <name>kumi::predicate</name>
      <anchorfile>group__utility_ga9c8c29e8a2f4f5e8a663200559fdc983.html</anchorfile>
      <anchor>ga9c8c29e8a2f4f5e8a663200559fdc983</anchor>
      <arglist>() noexcept</arglist>
    </member>
    <member kind="function">
      <type>KUMI_CUDA</type>
      <name>kumi::projection_map</name>
      <anchorfile>group__utility_ga3ba127205027539b3090467e2a504a24.html</anchorfile>
      <anchor>ga3ba127205027539b3090467e2a504a24</anchor>
      <arglist>(Ts...) -&gt; projection_map&lt; Ts... &gt;</arglist>
    </member>
    <member kind="function">
      <type>kumi::str constexpr</type>
      <name>to_str</name>
      <anchorfile>group__utility_gaf4584fa9d1d39f32081265df16e00364.html</anchorfile>
      <anchor>gaf4584fa9d1d39f32081265df16e00364</anchor>
      <arglist>(auto e)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::values_of</name>
      <anchorfile>group__utility_ga62d44b638af9c683a8040a476518990e.html</anchorfile>
      <anchor>ga62d44b638af9c683a8040a476518990e</anchor>
      <arglist>(T &amp;&amp;t) noexcept</arglist>
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
      <type>constexpr boolean_and</type>
      <name>kumi::function::bit_and</name>
      <anchorfile>group__utility.html</anchorfile>
      <anchor>gaa04ecc72014400d45d9ebb72bd7447cc</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr boolean_or</type>
      <name>kumi::function::bit_or</name>
      <anchorfile>group__utility.html</anchorfile>
      <anchor>gac095643bedb84ce2b3fdf1bd0c4a9cc3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr boolean_xor</type>
      <name>kumi::function::bit_xor</name>
      <anchorfile>group__utility.html</anchorfile>
      <anchor>gac2d793601af17db10563acf07dc1a29f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr traits_check&lt; Traits &gt;</type>
      <name>kumi::if_</name>
      <anchorfile>group__utility_gacadc026868e6654e80c57432643c804a.html</anchorfile>
      <anchor>gacadc026868e6654e80c57432643c804a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr index_t&lt; N &gt; const</type>
      <name>kumi::index</name>
      <anchorfile>group__utility.html</anchorfile>
      <anchor>ga32a67892e5dbfb93a2292959a5a029d0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr numeric_prod</type>
      <name>kumi::function::multiplies</name>
      <anchorfile>group__utility.html</anchorfile>
      <anchor>gaaab79e5ddd9913e237c23b6ebbe0d274</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr unit</type>
      <name>kumi::none</name>
      <anchorfile>group__utility.html</anchorfile>
      <anchor>gabe662caa7eff683f6b085c7abb76391b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr only_t&lt; T &gt;</type>
      <name>kumi::only</name>
      <anchorfile>group__utility_ga6a8e75139bc622fbedae986420916d98.html</anchorfile>
      <anchor>ga6a8e75139bc622fbedae986420916d98</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr numeric_add</type>
      <name>kumi::function::plus</name>
      <anchorfile>group__utility.html</anchorfile>
      <anchor>gab5c0eb8022e7b2df33286d9a15247559</anchor>
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
      <anchorfile>group__reductions_gae9e0f77ffe8399c701ba32532db19d11.html</anchorfile>
      <anchor>gae9e0f77ffe8399c701ba32532db19d11</anchor>
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
      <anchorfile>group__generators_ga0cf18e9f5c176d132be6afbfcb6652ae.html</anchorfile>
      <anchor>ga0cf18e9f5c176d132be6afbfcb6652ae</anchor>
      <arglist>(Ts &amp;&amp;... ts)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::cat</name>
      <anchorfile>group__generators_ga3786266bedb7981ba0df79cc5b49b261.html</anchorfile>
      <anchor>ga3786266bedb7981ba0df79cc5b49b261</anchor>
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
      <anchorfile>group__generators_ga2238e054e2c2a2160bec88e3c47e7691.html</anchorfile>
      <anchor>ga2238e054e2c2a2160bec88e3c47e7691</anchor>
      <arglist>(T &amp;&amp;t, index_t&lt; I0 &gt; i0, index_t&lt; I1 &gt; i1) noexcept</arglist>
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
      <anchorfile>group__generators_ga9a705331b78493a8882f9db889b57bc9.html</anchorfile>
      <anchor>ga9a705331b78493a8882f9db889b57bc9</anchor>
      <arglist>(T &amp;&amp;t, index_t&lt; I0 &gt; i0) noexcept</arglist>
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
      <anchorfile>group__generators_ga6fcdd03f2a3360cbb976cf05e0b0468c.html</anchorfile>
      <anchor>ga6fcdd03f2a3360cbb976cf05e0b0468c</anchor>
      <arglist>(T0 &amp;&amp;t0, Ts &amp;&amp;... ts)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::zip_max</name>
      <anchorfile>group__generators_gad2b81bc979a4089affddfdbef866e80b.html</anchorfile>
      <anchor>gad2b81bc979a4089affddfdbef866e80b</anchor>
      <arglist>(T0 &amp;&amp;t0, Ts &amp;&amp;... ts)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::zip_min</name>
      <anchorfile>group__generators_ga90d498013e5f387b2c906a4184644979.html</anchorfile>
      <anchor>ga90d498013e5f387b2c906a4184644979</anchor>
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
      <type>constexpr bool</type>
      <name>kumi::contains</name>
      <anchorfile>group__queries_gad40223aadd1f05d53a30e36f679d4d4a.html</anchorfile>
      <anchor>gad40223aadd1f05d53a30e36f679d4d4a</anchor>
      <arglist>(T &amp;&amp;t, ID const &amp;id) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr bool</type>
      <name>kumi::contains_any</name>
      <anchorfile>group__queries_ga99602610074451fe87591793d992ba01.html</anchorfile>
      <anchor>ga99602610074451fe87591793d992ba01</anchor>
      <arglist>(T &amp;&amp;t, Is const &amp;... ids) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr bool</type>
      <name>kumi::contains_none</name>
      <anchorfile>group__queries_gaaa03ad56a0a8a76d8a6e88557cab92a1.html</anchorfile>
      <anchor>gaaa03ad56a0a8a76d8a6e88557cab92a1</anchor>
      <arglist>(T &amp;&amp;t, Is const &amp;... ids) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr bool</type>
      <name>kumi::contains_only</name>
      <anchorfile>group__queries_ga0c0a9c717f4825fcb0a75add9bf2a838.html</anchorfile>
      <anchor>ga0c0a9c717f4825fcb0a75add9bf2a838</anchor>
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
    <subgroup>record_concepts</subgroup>
    <subgroup>tuple_concepts</subgroup>
    <concept>kumi::concepts::compatible_product_types</concept>
    <concept>kumi::concepts::container</concept>
    <concept>kumi::concepts::contains_field</concept>
    <concept>kumi::concepts::contains_type</concept>
    <concept>kumi::concepts::empty_product_type</concept>
    <concept>kumi::concepts::entirely_uniquely_named</concept>
    <concept>kumi::concepts::equality_comparable</concept>
    <concept>kumi::concepts::equivalent</concept>
    <concept>kumi::concepts::field</concept>
    <concept>kumi::concepts::follows_same_semantic</concept>
    <concept>kumi::concepts::has_named_fields</concept>
    <concept>kumi::concepts::homogeneous_product_type</concept>
    <concept>kumi::concepts::identifier</concept>
    <concept>kumi::concepts::is_fully_named</concept>
    <concept>kumi::concepts::monoid</concept>
    <concept>kumi::concepts::named_equality_comparable</concept>
    <concept>kumi::concepts::named_get_compliant</concept>
    <concept>kumi::concepts::non_empty_product_type</concept>
    <concept>kumi::concepts::product_type</concept>
    <concept>kumi::concepts::projection</concept>
    <concept>kumi::concepts::projection_map</concept>
    <concept>kumi::concepts::record_type</concept>
    <concept>kumi::concepts::sized_product_type</concept>
    <concept>kumi::concepts::sized_product_type_or_more</concept>
    <concept>kumi::concepts::static_container</concept>
    <concept>kumi::concepts::typed_get_compliant</concept>
    <concept>kumi::concepts::unique_label</concept>
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
    <class kind="struct">kumi::common_product_type</class>
    <class kind="struct">kumi::container_size</class>
    <class kind="struct">kumi::container_type</class>
    <class kind="struct">kumi::element</class>
    <class kind="struct">kumi::has_static_size</class>
    <class kind="struct">kumi::is_container</class>
    <class kind="struct">kumi::is_product_type</class>
    <class kind="struct">kumi::is_record_type</class>
    <class kind="struct">kumi::member</class>
    <class kind="struct">kumi::raw_member</class>
    <class kind="struct">kumi::size</class>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>kumi::is_projection_map_v</name>
      <anchorfile>group__traits_ga3a312d9c4dd445cbd5d152c6a02ca015.html</anchorfile>
      <anchor>ga3a312d9c4dd445cbd5d152c6a02ca015</anchor>
      <arglist></arglist>
    </member>
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
      <anchorfile>group__transforms_ga743a481a92dcc85b86159a44a562dd77.html</anchorfile>
      <anchor>ga743a481a92dcc85b86159a44a562dd77</anchor>
      <arglist>(Function f, T &amp;&amp;t, Ts &amp;&amp;... ts)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::map</name>
      <anchorfile>group__transforms_ga446a1438a421885ef0a52c3933d0be5a.html</anchorfile>
      <anchor>ga446a1438a421885ef0a52c3933d0be5a</anchor>
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
      <anchorfile>group__tuple__related_ga1a3be7d170cb81c6f87c93a0a04eabc8.html</anchorfile>
      <anchor>ga1a3be7d170cb81c6f87c93a0a04eabc8</anchor>
      <arglist>(Ts &amp;... ts) -&gt; tuple&lt; Ts &amp;... &gt;</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::forward_as_tuple</name>
      <anchorfile>group__tuple__related_ga5288a0680596f3c52e7313b964a60746.html</anchorfile>
      <anchor>ga5288a0680596f3c52e7313b964a60746</anchor>
      <arglist>(Ts &amp;&amp;... ts) -&gt; tuple&lt; Ts &amp;&amp;... &gt;</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::make_tuple</name>
      <anchorfile>group__tuple__related_ga98e6c367de0e0f526565280a0856b007.html</anchorfile>
      <anchor>ga98e6c367de0e0f526565280a0856b007</anchor>
      <arglist>(Ts &amp;&amp;... ts) -&gt; tuple&lt; std::unwrap_ref_decay_t&lt; Ts &gt;... &gt;</arglist>
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
      <anchorfile>group__tuple__related_gaf717514dbb49e0bf526bf5c9e2c693c5.html</anchorfile>
      <anchor>gaf717514dbb49e0bf526bf5c9e2c693c5</anchor>
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
    <name>record_concepts</name>
    <title>Record Related Concepts</title>
    <filename>group__record__concepts.html</filename>
  </compound>
  <compound kind="group">
    <name>record_traits</name>
    <title>Record Related Traits</title>
    <filename>group__record__traits.html</filename>
    <class kind="struct">kumi::raw_element</class>
  </compound>
  <compound kind="group">
    <name>record_transforms</name>
    <title>Record Type Specific Transformations</title>
    <filename>group__record__transforms.html</filename>
    <member kind="function">
      <type>constexpr void</type>
      <name>kumi::for_each_field</name>
      <anchorfile>group__record__transforms_ga15399097726371208bf338ce69088447.html</anchorfile>
      <anchor>ga15399097726371208bf338ce69088447</anchor>
      <arglist>(Function f, R &amp;&amp;r, Rs &amp;&amp;... rs)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::map_field</name>
      <anchorfile>group__record__transforms_ga325ce53da1e1706c3bba9c40e8477f20.html</anchorfile>
      <anchor>ga325ce53da1e1706c3bba9c40e8477f20</anchor>
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
      <anchorfile>group__record__related_ga3908d4824c3feaf359d906b670ad8439.html</anchorfile>
      <anchor>ga3908d4824c3feaf359d906b670ad8439</anchor>
      <arglist>(Ts &amp;... ts) -&gt; record&lt; field&lt; decltype(Fields), Ts &amp; &gt;... &gt; requires(sizeof...(Fields)==sizeof...(Ts))</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::forward_as_record</name>
      <anchorfile>group__record__related_ga8f10ae45fab799e4d4c03d9aca17f68c.html</anchorfile>
      <anchor>ga8f10ae45fab799e4d4c03d9aca17f68c</anchor>
      <arglist>(Ts &amp;&amp;... ts) -&gt; record&lt; field&lt; decltype(Fields), Ts &amp;&amp; &gt;... &gt; requires(sizeof...(Fields)==sizeof...(Ts))</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::make_record</name>
      <anchorfile>group__record__related_ga76eb17a90f4e3752c96633b20a62969f.html</anchorfile>
      <anchor>ga76eb17a90f4e3752c96633b20a62969f</anchor>
      <arglist>(Ts &amp;&amp;... ts) -&gt; record&lt; std::unwrap_ref_decay_t&lt; Ts &gt;... &gt; requires(concepts::entirely_uniquely_named&lt; Ts... &gt;)</arglist>
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
      <anchorfile>group__record__related_ga7c267951118dab695ae5bd0f4d64895e.html</anchorfile>
      <anchor>ga7c267951118dab695ae5bd0f4d64895e</anchor>
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
    <name>tuple_concepts</name>
    <title>Tuple Related Concepts</title>
    <filename>group__tuple__concepts.html</filename>
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
      <anchorfile>group__tuple__transforms_ga68e0e98957242f48da8dfeeaa29fec7d.html</anchorfile>
      <anchor>ga68e0e98957242f48da8dfeeaa29fec7d</anchor>
      <arglist>(Function f, T &amp;&amp;t, Ts &amp;&amp;... ts)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::map_index</name>
      <anchorfile>group__tuple__transforms_ga23eac0bc61cc84e8feabf8f67f438124.html</anchorfile>
      <anchor>ga23eac0bc61cc84e8feabf8f67f438124</anchor>
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
